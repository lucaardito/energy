//#include <windows.h>


#include <stdarg.h>     // So we can use ... (in dprintf)
#include <stdio.h>		// sprintf(..), fopen(..)
#include <stdlib.h>		// atoi()
#include <stdarg.h>     // So we can use ... (in dprintf)
#include <string.h>		// memset(..)
#include <math.h>		// sqrt(..), cos(..)
#include <malloc.h>
#include <time.h>
#include <iostream>

//#include "loadjpg.h"	// ConvertJpgFile(..)
#define LOADJPG_H
#define SAVEJPG_H
#define BYTE unsigned char
#define SBYTE signed char
#define SWORD signed short int
#define WORD unsigned short int
#define DWORD unsigned long int
#define SDWORD signed long int

/*
	scalefactor controls the visual quality of the image
	the smaller is, the better image we'll get, and the smaller
	compression we'll achieve
*/
BYTE scalefactor;

static struct APP0infotype {
		WORD marker;// = 0xFFE0
		WORD length; // = 16 for usual JPEG, no thumbnail
		BYTE JFIFsignature[5]; // = "JFIF",'\0'
		BYTE versionhi; // 1
		BYTE versionlo; // 1
		BYTE xyunits;   // 0 = no units, normal density
		WORD xdensity;  // 1
		WORD ydensity;  // 1
		BYTE thumbnwidth; // 0
		BYTE thumbnheight; // 0
} APP0info={0xFFE0,16,'J','F','I','F',0,1,1,0,1,1,0,0};

static struct  SOF0infotype {
		WORD marker; // = 0xFFC0
		WORD length; // = 17 for a truecolor YCbCr JPG
		BYTE precision ;// Should be 8: 8 bits/sample
		WORD height ;
		WORD width;
		BYTE nrofcomponents;//Should be 3: We encode a truecolor JPG
		BYTE IdY;  // = 1
		BYTE HVY; // sampling factors for Y (bit 0-3 vert., 4-7 hor.)
		BYTE QTY;  // Quantization Table number for Y = 0
		BYTE IdCb; // = 2
		BYTE HVCb;
		BYTE QTCb; // 1
		BYTE IdCr; // = 3
		BYTE HVCr;
		BYTE QTCr; // Normally equal to QTCb = 1
} SOF0info = { 0xFFC0,17,8,0,0,3,1,0x11,0,2,0x11,1,3,0x11,1};
// Default sampling factors are 1,1 for every image component: No downsampling

static struct DQTinfotype {
		 WORD marker;  // = 0xFFDB
		 WORD length;  // = 132
		 BYTE QTYinfo;// = 0:  bit 0..3: number of QT = 0 (table for Y)
				  //       bit 4..7: precision of QT, 0 = 8 bit
		 BYTE Ytable[64];
		 BYTE QTCbinfo; // = 1 (quantization table for Cb,Cr}
		 BYTE Cbtable[64];
		   } DQTinfo;
// Ytable from DQTinfo should be equal to a scaled and zizag reordered version
// of the table which can be found in "tables.h": std_luminance_qt
// Cbtable , similar = std_chrominance_qt
// We'll init them in the program using set_DQTinfo function

static struct DHTinfotype {
		 WORD marker;  // = 0xFFC4
		 WORD length;  //0x01A2
		 BYTE HTYDCinfo; // bit 0..3: number of HT (0..3), for Y =0
			  //bit 4  :type of HT, 0 = DC table,1 = AC table
				//bit 5..7: not used, must be 0
		 BYTE YDC_nrcodes[16]; //at index i = nr of codes with length i
		 BYTE YDC_values[12];
		 BYTE HTYACinfo; // = 0x10
		 BYTE YAC_nrcodes[16];
		 BYTE YAC_values[162];//we'll use the standard Huffman tables
		 BYTE HTCbDCinfo; // = 1
		 BYTE CbDC_nrcodes[16];
		 BYTE CbDC_values[12];
		 BYTE HTCbACinfo; //  = 0x11
		 BYTE CbAC_nrcodes[16];
		 BYTE CbAC_values[162];
} DHTinfo;

static struct SOSinfotype {
		 WORD marker;  // = 0xFFDA
		 WORD length; // = 12
		 BYTE nrofcomponents; // Should be 3: truecolor JPG
		 BYTE IdY; //1
		 BYTE HTY; //0 // bits 0..3: AC table (0..3)
				   // bits 4..7: DC table (0..3)
		 BYTE IdCb; //2
		 BYTE HTCb; //0x11
		 BYTE IdCr; //3
		 BYTE HTCr; //0x11
		 BYTE Ss,Se,Bf; // not interesting, they should be 0,63,0
} SOSinfo={0xFFDA,12,3,1,0,2,0x11,3,0x11,0,0x3F,0};

typedef struct { BYTE B,G,R; } colorRGB;
typedef struct { BYTE length;
		 WORD value;} bitstring;

#define  Y(R,G,B) ((BYTE)( (YRtab[(R)]+YGtab[(G)]+YBtab[(B)])>>16 ) - 128)
#define Cb(R,G,B) ((BYTE)( (CbRtab[(R)]+CbGtab[(G)]+CbBtab[(B)])>>16 ) )
#define Cr(R,G,B) ((BYTE)( (CrRtab[(R)]+CrGtab[(G)]+CrBtab[(B)])>>16 ) )

#define writebyte(b) fputc((b),fp_jpeg_stream)
#define writeword(w) writebyte((w)/256);writebyte((w)%256);



static BYTE zigzag[64]={ 0, 1, 5, 6,14,15,27,28,
		  2, 4, 7,13,16,26,29,42,
		  3, 8,12,17,25,30,41,43,
		  9,11,18,24,31,40,44,53,
		 10,19,23,32,39,45,52,54,
		 20,22,33,38,46,51,55,60,
		 21,34,37,47,50,56,59,61,
		 35,36,48,49,57,58,62,63 };

//These are the sample quantization tables given in JPEG spec section K.1.
//	The spec says that the values given produce "good" quality, and
//	when divided by 2, "very good" quality
static unsigned char std_luminance_qt[64] = {
	16,  11,  10,  16,  24,  40,  51,  61,
	12,  12,  14,  19,  26,  58,  60,  55,
	14,  13,  16,  24,  40,  57,  69,  56,
	14,  17,  22,  29,  51,  87,  80,  62,
	18,  22,  37,  56,  68, 109, 103,  77,
	24,  35,  55,  64,  81, 104, 113,  92,
	49,  64,  78,  87, 103, 121, 120, 101,
	72,  92,  95,  98, 112, 100, 103,  99
  };
static unsigned char std_chrominance_qt[64] = {
	17,  18,  24,  47,  99,  99,  99,  99,
	18,  21,  26,  66,  99,  99,  99,  99,
	24,  26,  56,  99,  99,  99,  99,  99,
	47,  66,  99,  99,  99,  99,  99,  99,
	99,  99,  99,  99,  99,  99,  99,  99,
	99,  99,  99,  99,  99,  99,  99,  99,
	99,  99,  99,  99,  99,  99,  99,  99,
	99,  99,  99,  99,  99,  99,  99,  99
  };


  //High ration 1:45
//
//  static unsigned char std_luminance_qt[64] = {
//	1,  2,  4,  6,  16, 32, 64, 128 ,
//	2,  4,  4,  8,  16, 32, 64, 128,
//	4,  4,  8,  16, 32, 64, 128, 128,
//	8,  8,  16, 32, 64, 128, 128, 256,
//	16, 16, 32, 64, 128, 128, 256, 256,
//	32,  32,  64,  128,  128, 256, 256, 256,
//	64,  64,  128,  128, 256, 256, 256, 256,
//	128,  128,  128,  256, 256, 256, 256,  256
//  };
//static unsigned char std_chrominance_qt[64] = {
//	17,  18,  24,  47,  99,  99,  99,  99,
//	18,  21,  26,  66,  99,  99,  99,  99,
//	24,  26,  56,  99,  99,  99,  99,  99,
//	47,  66,  99,  99,  99,  99,  99,  99,
//	99,  99,  99,  99,  99,  99,  99,  99,
//	99,  99,  99,  99,  99,  99,  99,  99,
//	99,  99,  99,  99,  99,  99,  99,  99,
//	99,  99,  99,  99,  99,  99,  99,  99
//  };



// Standard Huffman tables (cf. JPEG standard section K.3)

static unsigned char std_dc_luminance_nrcodes[17]={0,0,1,5,1,1,1,1,1,1,0,0,0,0,0,0,0};
static unsigned char std_dc_luminance_values[12]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

static unsigned char std_dc_chrominance_nrcodes[17]={0,0,3,1,1,1,1,1,1,1,1,1,0,0,0,0,0};
static unsigned char std_dc_chrominance_values[12]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

static unsigned char std_ac_luminance_nrcodes[17]={0,0,2,1,3,3,2,4,3,5,5,4,4,0,0,1,0x7d };
static unsigned char std_ac_luminance_values[162]= {
	  0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12,
	  0x21, 0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07,
	  0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08,
	  0x23, 0x42, 0xb1, 0xc1, 0x15, 0x52, 0xd1, 0xf0,
	  0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0a, 0x16,
	  0x17, 0x18, 0x19, 0x1a, 0x25, 0x26, 0x27, 0x28,
	  0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
	  0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
	  0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
	  0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
	  0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
	  0x7a, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
	  0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98,
	  0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
	  0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6,
	  0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5,
	  0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4,
	  0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe1, 0xe2,
	  0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea,
	  0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8,
	  0xf9, 0xfa };

static BYTE std_ac_chrominance_nrcodes[17]={0,0,2,1,2,4,4,3,4,7,5,4,4,0,1,2,0x77};
static BYTE std_ac_chrominance_values[162]={
	  0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21,
	  0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71,
	  0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91,
	  0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0,
	  0x15, 0x62, 0x72, 0xd1, 0x0a, 0x16, 0x24, 0x34,
	  0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26,
	  0x27, 0x28, 0x29, 0x2a, 0x35, 0x36, 0x37, 0x38,
	  0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	  0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	  0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
	  0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
	  0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
	  0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96,
	  0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5,
	  0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4,
	  0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3,
	  0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2,
	  0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda,
	  0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
	  0xea, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8,
	  0xf9, 0xfa };






void SaveJpgFile(char *szBmpFileNameIn, char* szJpgFileNameOut);
/***************************************************************************/

static unsigned char bytenew=0; // The byte that will be written in the JPG file
static SBYTE bytepos=7; //bit position in the byte we write (bytenew)
			//should be<=7 and >=0
static WORD mask[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

// The Huffman tables we'll use:
static bitstring YDC_HT[12];
static bitstring CbDC_HT[12];
static bitstring YAC_HT[256];
static bitstring CbAC_HT[256];

static unsigned char *category_alloc;
static unsigned char *category; //Here we'll keep the category of the numbers in range: -32767..32767
static bitstring *bitcode_alloc;
static bitstring *bitcode; // their bitcoded representation

//Precalculated tables for a faster YCbCr->RGB transformation
// We use a SDWORD table because we'll scale values by 2^16 and work with integers
static SDWORD YRtab[256],YGtab[256],YBtab[256];
static SDWORD CbRtab[256],CbGtab[256],CbBtab[256];
static SDWORD CrRtab[256],CrGtab[256],CrBtab[256];
static float fdtbl_Y[64];
static float fdtbl_Cb[64]; //the same with the fdtbl_Cr[64]

static colorRGB *RGB_buffer; //image to be encoded
static WORD Ximage,Yimage;// image dimensions divisible by 8
static SBYTE YDU[64]; // This is the Data Unit of Y after YCbCr->RGB transformation
static SBYTE CbDU[64];
static SBYTE CrDU[64];
static SWORD DU_DCT[64]; // Current DU (after DCT and quantization) which we'll zigzag
static SWORD DU[64]; //zigzag reordered DU which will be Huffman coded

static FILE *fp_jpeg_stream;


/***************************************************************************/


void write_APP0info()
//Nothing to overwrite for APP0info
{
 writeword(APP0info.marker);
 writeword(APP0info.length);
 writebyte('J');writebyte('F');writebyte('I');writebyte('F');writebyte(0);
 writebyte(APP0info.versionhi);writebyte(APP0info.versionlo);
 writebyte(APP0info.xyunits);
 writeword(APP0info.xdensity);writeword(APP0info.ydensity);
 writebyte(APP0info.thumbnwidth);writebyte(APP0info.thumbnheight);
}

void write_SOF0info()
// We should overwrite width and height
{
 writeword(SOF0info.marker);
 writeword(SOF0info.length);
 writebyte(SOF0info.precision);
 writeword(SOF0info.height);writeword(SOF0info.width);
 writebyte(SOF0info.nrofcomponents);
 writebyte(SOF0info.IdY);writebyte(SOF0info.HVY);writebyte(SOF0info.QTY);
 writebyte(SOF0info.IdCb);writebyte(SOF0info.HVCb);writebyte(SOF0info.QTCb);
 writebyte(SOF0info.IdCr);writebyte(SOF0info.HVCr);writebyte(SOF0info.QTCr);
}

void write_DQTinfo()
{
 BYTE i;
 writeword(DQTinfo.marker);
 writeword(DQTinfo.length);
 writebyte(DQTinfo.QTYinfo);for (i=0;i<64;i++) writebyte(DQTinfo.Ytable[i]);
 writebyte(DQTinfo.QTCbinfo);for (i=0;i<64;i++) writebyte(DQTinfo.Cbtable[i]);
}

void set_quant_table(BYTE *basic_table,BYTE scale_factor,BYTE *newtable)
// Set quantization table and zigzag reorder it
{
 BYTE i;
 long temp;
 for (i = 0; i < 64; i++) {
      temp = ((long) basic_table[i] * scale_factor + 50L) / 100L;
	//limit the values to the valid range
    if (temp <= 0L) temp = 1L;
    if (temp > 255L) temp = 255L; //limit to baseline range if requested
    newtable[zigzag[i]] = (BYTE) temp;
			  }
}

void set_DQTinfo()
{
 DQTinfo.marker=0xFFDB;
 DQTinfo.length=132;
 DQTinfo.QTYinfo=0;
 DQTinfo.QTCbinfo=1;
 set_quant_table(std_luminance_qt,scalefactor,DQTinfo.Ytable);
 set_quant_table(std_chrominance_qt,scalefactor,DQTinfo.Cbtable);
}

void write_DHTinfo()
{
 BYTE i;
 writeword(DHTinfo.marker);
 writeword(DHTinfo.length);
 writebyte(DHTinfo.HTYDCinfo);
 for (i=0;i<16;i++)  writebyte(DHTinfo.YDC_nrcodes[i]);
 for (i=0;i<=11;i++) writebyte(DHTinfo.YDC_values[i]);
 writebyte(DHTinfo.HTYACinfo);
 for (i=0;i<16;i++)  writebyte(DHTinfo.YAC_nrcodes[i]);
 for (i=0;i<=161;i++) writebyte(DHTinfo.YAC_values[i]);
 writebyte(DHTinfo.HTCbDCinfo);
 for (i=0;i<16;i++)  writebyte(DHTinfo.CbDC_nrcodes[i]);
 for (i=0;i<=11;i++)  writebyte(DHTinfo.CbDC_values[i]);
 writebyte(DHTinfo.HTCbACinfo);
 for (i=0;i<16;i++)  writebyte(DHTinfo.CbAC_nrcodes[i]);
 for (i=0;i<=161;i++) writebyte(DHTinfo.CbAC_values[i]);
}

void set_DHTinfo()
{
 BYTE i;
 DHTinfo.marker=0xFFC4;
 DHTinfo.length=0x01A2;
 DHTinfo.HTYDCinfo=0;
 for (i=0;i<16;i++)  DHTinfo.YDC_nrcodes[i]=std_dc_luminance_nrcodes[i+1];
 for (i=0;i<=11;i++)  DHTinfo.YDC_values[i]=std_dc_luminance_values[i];
 DHTinfo.HTYACinfo=0x10;
 for (i=0;i<16;i++)  DHTinfo.YAC_nrcodes[i]=std_ac_luminance_nrcodes[i+1];
 for (i=0;i<=161;i++) DHTinfo.YAC_values[i]=std_ac_luminance_values[i];
 DHTinfo.HTCbDCinfo=1;
 for (i=0;i<16;i++)  DHTinfo.CbDC_nrcodes[i]=std_dc_chrominance_nrcodes[i+1];
 for (i=0;i<=11;i++)  DHTinfo.CbDC_values[i]=std_dc_chrominance_values[i];
 DHTinfo.HTCbACinfo=0x11;
 for (i=0;i<16;i++)  DHTinfo.CbAC_nrcodes[i]=std_ac_chrominance_nrcodes[i+1];
 for (i=0;i<=161;i++) DHTinfo.CbAC_values[i]=std_ac_chrominance_values[i];
}

void write_SOSinfo()
//Nothing to overwrite for SOSinfo
{
 writeword(SOSinfo.marker);
 writeword(SOSinfo.length);
 writebyte(SOSinfo.nrofcomponents);
 writebyte(SOSinfo.IdY);writebyte(SOSinfo.HTY);
 writebyte(SOSinfo.IdCb);writebyte(SOSinfo.HTCb);
 writebyte(SOSinfo.IdCr);writebyte(SOSinfo.HTCr);
 writebyte(SOSinfo.Ss);writebyte(SOSinfo.Se);writebyte(SOSinfo.Bf);
}

void write_comment(BYTE *comment)
{
 WORD i,length;
 writeword(0xFFFE); //The COM marker
 length=(WORD)strlen((const char *)comment);
 writeword(length+2);
 for (i=0;i<length;i++) writebyte(comment[i]);
}

void writebits(bitstring bs)
// A portable version; it should be done in assembler
{
 WORD value;
 SBYTE posval;//bit position in the bitstring we read, should be<=15 and >=0
 value=bs.value;
 posval=bs.length-1;
 while (posval>=0)
  {
   if (value & mask[posval]) bytenew|=mask[bytepos];
   posval--;bytepos--;
   if (bytepos<0) { if (bytenew==0xFF) {writebyte(0xFF);writebyte(0);}
		     else {writebyte(bytenew);}
		    bytepos=7;bytenew=0;
		  }
  }
}

void compute_Huffman_table(BYTE *nrcodes,BYTE *std_table,bitstring *HT)
{
 BYTE k,j;
 BYTE pos_in_table;
 WORD codevalue;
 codevalue=0; pos_in_table=0;
 for (k=1;k<=16;k++)
   {
     for (j=1;j<=nrcodes[k];j++) {HT[std_table[pos_in_table]].value=codevalue;
				  HT[std_table[pos_in_table]].length=k;
				  pos_in_table++;
				  codevalue++;
				 }
     codevalue*=2;
   }
}
void init_Huffman_tables()
{
 compute_Huffman_table(std_dc_luminance_nrcodes,std_dc_luminance_values,YDC_HT);
 compute_Huffman_table(std_dc_chrominance_nrcodes,std_dc_chrominance_values,CbDC_HT);
 compute_Huffman_table(std_ac_luminance_nrcodes,std_ac_luminance_values,YAC_HT);
 compute_Huffman_table(std_ac_chrominance_nrcodes,std_ac_chrominance_values,CbAC_HT);
}

void exitmessage(char const *error_message)
{
 printf("%s\n",error_message);//exit(EXIT_FAILURE);
}

void set_numbers_category_and_bitcode()
{
 SDWORD nr;
 SDWORD nrlower,nrupper;
 unsigned char cat;

 category_alloc=(unsigned char *)malloc(65535*sizeof(unsigned char));
 if (category_alloc==NULL) exitmessage("Not enough memory.");
 category=category_alloc+32767; //allow negative subscripts
 bitcode_alloc=(bitstring *)malloc(65535*sizeof(bitstring));
 if (bitcode_alloc==NULL) exitmessage("Not enough memory.");
 bitcode=bitcode_alloc+32767;
 nrlower=1;nrupper=2;
 for (cat=1;cat<=15;cat++) {
				 //Positive numbers
				 for (nr=nrlower;nr<nrupper;nr++)
				  { category[nr]=cat;
				bitcode[nr].length=cat;
				bitcode[nr].value=(WORD)nr;
				  }
				 //Negative numbers
				 for (nr=-(nrupper-1);nr<=-nrlower;nr++)
				  { category[nr]=cat;
				bitcode[nr].length=cat;
				bitcode[nr].value=(WORD)(nrupper-1+nr);
				  }
				 nrlower<<=1;
				 nrupper<<=1;
			   }
}

void precalculate_YCbCr_tables()
{
 WORD R,G,B;
 for (R=0;R<=255;R++) {YRtab[R]=(SDWORD)(65536*0.299+0.5)*R;
			   CbRtab[R]=(SDWORD)(65536*-0.16874+0.5)*R;
			   CrRtab[R]=(SDWORD)(32768)*R;
			  }
 for (G=0;G<=255;G++) {YGtab[G]=(SDWORD)(65536*0.587+0.5)*G;
			   CbGtab[G]=(SDWORD)(65536*-0.33126+0.5)*G;
			   CrGtab[G]=(SDWORD)(65536*-0.41869+0.5)*G;
			  }
 for (B=0;B<=255;B++) {YBtab[B]=(SDWORD)(65536*0.114+0.5)*B;
			   CbBtab[B]=(SDWORD)(32768)*B;
			   CrBtab[B]=(SDWORD)(65536*-0.08131+0.5)*B;
			  }
}

// Using a bit modified form of the FDCT routine from IJG's C source:
// Forward DCT routine idea taken from Independent JPEG Group's C source for
// JPEG encoders/decoders

// For float AA&N IDCT method, divisors are equal to quantization
//   coefficients scaled by scalefactor[row]*scalefactor[col], where
//   scalefactor[0] = 1
//   scalefactor[k] = cos(k*PI/16) * sqrt(2)    for k=1..7
//   We apply a further scale factor of 8.
//   What's actually stored is 1/divisor so that the inner loop can
//   use a multiplication rather than a division.
void prepare_quant_tables()
{
 double aanscalefactor[8] = {1.0, 1.387039845, 1.306562965, 1.175875602,
			   1.0, 0.785694958, 0.541196100, 0.275899379};
 BYTE row, col;
 BYTE i = 0;
 for (row = 0; row < 8; row++)
 {
   for (col = 0; col < 8; col++)
     {
       fdtbl_Y[i] = (float) (1.0 / ((double) DQTinfo.Ytable[zigzag[i]] *
			  aanscalefactor[row] * aanscalefactor[col] * 8.0));
       fdtbl_Cb[i] = (float) (1.0 / ((double) DQTinfo.Cbtable[zigzag[i]] *
			  aanscalefactor[row] * aanscalefactor[col] * 8.0));

	   i++;
     }
 }
}

void fdct_and_quantization(SBYTE *data,float *fdtbl,SWORD *outdata)
{
  float tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  float tmp10, tmp11, tmp12, tmp13;
  float z1, z2, z3, z4, z5, z11, z13;
  float *dataptr;
  float datafloat[64];
  float temp;
  SBYTE ctr;
  BYTE i;
  for (i=0;i<64;i++) datafloat[i]=data[i];

  // Pass 1: process rows.
  dataptr=datafloat;
  for (ctr = 7; ctr >= 0; ctr--) {
	tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

	// Even part

    tmp10 = tmp0 + tmp3;	// phase 2
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = tmp10 + tmp11; // phase 3
    dataptr[4] = tmp10 - tmp11;

    z1 = (tmp12 + tmp13) * ((float) 0.707106781); // c4
	dataptr[2] = tmp13 + z1;	// phase 5
    dataptr[6] = tmp13 - z1;

    // Odd part

    tmp10 = tmp4 + tmp5;	// phase 2
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;

	// The rotator is modified from fig 4-8 to avoid extra negations
    z5 = (tmp10 - tmp12) * ((float) 0.382683433); // c6
    z2 = ((float) 0.541196100) * tmp10 + z5; // c2-c6
    z4 = ((float) 1.306562965) * tmp12 + z5; // c2+c6
    z3 = tmp11 * ((float) 0.707106781); // c4

    z11 = tmp7 + z3;		// phase 5
    z13 = tmp7 - z3;

    dataptr[5] = z13 + z2;	// phase 6
    dataptr[3] = z13 - z2;
	dataptr[1] = z11 + z4;
    dataptr[7] = z11 - z4;

    dataptr += 8;		//advance pointer to next row
  }

  // Pass 2: process columns

  dataptr = datafloat;
  for (ctr = 7; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[56];
    tmp7 = dataptr[0] - dataptr[56];
    tmp1 = dataptr[8] + dataptr[48];
    tmp6 = dataptr[8] - dataptr[48];
    tmp2 = dataptr[16] + dataptr[40];
    tmp5 = dataptr[16] - dataptr[40];
    tmp3 = dataptr[24] + dataptr[32];
    tmp4 = dataptr[24] - dataptr[32];

    //Even part/

    tmp10 = tmp0 + tmp3;	//phase 2
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = tmp10 + tmp11; // phase 3
    dataptr[32] = tmp10 - tmp11;

	z1 = (tmp12 + tmp13) * ((float) 0.707106781); // c4
    dataptr[16] = tmp13 + z1; // phase 5
    dataptr[48] = tmp13 - z1;

    // Odd part

    tmp10 = tmp4 + tmp5;	// phase 2
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;

    // The rotator is modified from fig 4-8 to avoid extra negations.
	z5 = (tmp10 - tmp12) * ((float) 0.382683433); // c6
    z2 = ((float) 0.541196100) * tmp10 + z5; // c2-c6
    z4 = ((float) 1.306562965) * tmp12 + z5; // c2+c6
    z3 = tmp11 * ((float) 0.707106781); // c4

    z11 = tmp7 + z3;		// phase 5
    z13 = tmp7 - z3;
    dataptr[40] = z13 + z2; // phase 6
	dataptr[24] = z13 - z2;
    dataptr[8] = z11 + z4;
    dataptr[56] = z11 - z4;

    dataptr++;			// advance pointer to next column
  }

// Quantize/descale the coefficients, and store into output array
 for (i = 0; i < 64; i++) {
 // Apply the quantization and scaling factor
			   temp = datafloat[i] * fdtbl[i];

   //Round to nearest integer.
   //Since C does not specify the direction of rounding for negative
   //quotients, we have to force the dividend positive for portability.
   //The maximum coefficient size is +-16K (for 12-bit data), so this
   //code should work for either 16-bit or 32-bit ints.

	   outdata[i] = (SWORD) ((SWORD)(temp + 16384.5) - 16384);
			  }
}

void process_DU(SBYTE *ComponentDU,float *fdtbl,SWORD *DC,
		bitstring *HTDC,bitstring *HTAC)
{
 bitstring EOB=HTAC[0x00];
 bitstring M16zeroes=HTAC[0xF0];
 BYTE i;
 BYTE startpos;
 BYTE end0pos;
 BYTE nrzeroes;
 BYTE nrmarker;
 SWORD Diff;

 fdct_and_quantization(ComponentDU,fdtbl,DU_DCT);
 //zigzag reorder
 for (i=0;i<=63;i++) DU[zigzag[i]]=DU_DCT[i];
 Diff=DU[0]-*DC;
 *DC=DU[0];
 //Encode DC
 if (Diff==0) writebits(HTDC[0]); //Diff might be 0
  else {
    writebits(HTDC[category[Diff]]);
	writebits(bitcode[Diff]);
       }
 //Encode ACs
 for (end0pos=63;(end0pos>0)&&(DU[end0pos]==0);end0pos--) ;
 //end0pos = first element in reverse order !=0
 if (end0pos==0) {writebits(EOB);return;}

 i=1;
 while (i<=end0pos)
  {
   startpos=i;
   for (; (DU[i]==0)&&(i<=end0pos);i++) ;
   nrzeroes=i-startpos;
   if (nrzeroes>=16) {
      for (nrmarker=1;nrmarker<=nrzeroes/16;nrmarker++) writebits(M16zeroes);
      nrzeroes=nrzeroes%16;
		     }
   writebits(HTAC[nrzeroes*16+category[DU[i]]]);writebits(bitcode[DU[i]]);
   i++;
  }
 if (end0pos!=63) writebits(EOB);
}

void load_data_units_from_RGB_buffer(WORD xpos,WORD ypos)
{
 BYTE x,y;
 BYTE pos=0;
 DWORD location;
 BYTE R,G,B;
 location=ypos*Ximage+xpos;
 for (y=0;y<8;y++)
 {
  for (x=0;x<8;x++)
   {
    R=RGB_buffer[location].R;G=RGB_buffer[location].G;B=RGB_buffer[location].B;
    YDU[pos]=Y(R,G,B);
    CbDU[pos]=Cb(R,G,B);
    CrDU[pos]=Cr(R,G,B);
    location++;pos++;
   }
  location+=Ximage-8;
 }
}

void main_encoder()
{
 SWORD DCY=0,DCCb=0,DCCr=0; //DC coefficients used for differential encoding
 WORD xpos,ypos;
 for (ypos=0;ypos<Yimage;ypos+=8)
  for (xpos=0;xpos<Ximage;xpos+=8)
   {
    load_data_units_from_RGB_buffer(xpos,ypos);
    process_DU(YDU,fdtbl_Y,&DCY,YDC_HT,YAC_HT);
    process_DU(CbDU,fdtbl_Cb,&DCCb,CbDC_HT,CbAC_HT);
    process_DU(CrDU,fdtbl_Cb,&DCCr,CbDC_HT,CbAC_HT);
   }
}

void load_bitmap(char *bitmap_name, WORD *Ximage_original, WORD *Yimage_original)
{
 WORD Xdiv8,Ydiv8;
 BYTE nr_fillingbytes;//The number of the filling bytes in the BMP file
     // (the dimension in bytes of a BMP line on the disk is divisible by 4)
 colorRGB lastcolor;
 WORD column;
 BYTE TMPBUF[256];
 WORD nrline_up,nrline_dn,nrline;
 WORD dimline;
 colorRGB *tmpline;
 FILE *fp_bitmap=fopen(bitmap_name,"rb");
 if (fp_bitmap==NULL) exitmessage("Cannot open bitmap file.File not found ?");
 if (fread(TMPBUF,1,54,fp_bitmap)!=54)
	 exitmessage("Need a truecolor BMP to encode.");
 if ((TMPBUF[0]!='B')||(TMPBUF[1]!='M')||(TMPBUF[28]!=24))
	 exitmessage("Need a truecolor BMP to encode.");
 Ximage=(WORD)TMPBUF[19]*256+TMPBUF[18];Yimage=(WORD)TMPBUF[23]*256+TMPBUF[22];
 *Ximage_original=Ximage;*Yimage_original=Yimage; //Keep the old dimensions
						// of the image
 if (Ximage%8!=0) Xdiv8=(Ximage/8)*8+8;
	else Xdiv8=Ximage;
 if (Yimage%8!=0) Ydiv8=(Yimage/8)*8+8;
	else Ydiv8=Yimage;
 // The image we encode shall be filled with the last line and the last column
 // from the original bitmap, until Ximage and Yimage are divisible by 8
 // Load BMP image from disk and complete X
 RGB_buffer=(colorRGB *)(malloc(3*Xdiv8*Ydiv8));
 if (RGB_buffer==NULL) exitmessage("Not enough memory for the bitmap image.");
 if (Ximage%4!=0) nr_fillingbytes=4-(Ximage%4);
  else nr_fillingbytes=0;
 for (nrline=0;nrline<Yimage;nrline++)
  {
   fread(RGB_buffer+nrline*Xdiv8,1,Ximage*3,fp_bitmap);
   fread(TMPBUF,1,nr_fillingbytes,fp_bitmap);
   memcpy(&lastcolor,RGB_buffer+nrline*Xdiv8+Ximage-1,3);
   for (column=Ximage;column<Xdiv8;column++)
	{memcpy(RGB_buffer+nrline*Xdiv8+column,&lastcolor,3);}
  }
 Ximage=Xdiv8;
 dimline=Ximage*3;tmpline=(colorRGB *)malloc(dimline);
 if (tmpline==NULL) exitmessage("Not enough memory.");
 //Reorder in memory the inversed bitmap
 for (nrline_up=Yimage-1,nrline_dn=0;nrline_up>nrline_dn;nrline_up--,nrline_dn++)
  {
   memcpy(tmpline,RGB_buffer+nrline_up*Ximage, dimline);
   memcpy(RGB_buffer+nrline_up*Ximage,RGB_buffer+nrline_dn*Ximage,dimline);
   memcpy(RGB_buffer+nrline_dn*Ximage,tmpline,dimline);
  }
 // Y completion:
 memcpy(tmpline,RGB_buffer+(Yimage-1)*Ximage,dimline);
 for (nrline=Yimage;nrline<Ydiv8;nrline++)
  {memcpy(RGB_buffer+nrline*Ximage,tmpline,dimline);}
 Yimage=Ydiv8;
 free(tmpline);fclose(fp_bitmap);
}

void init_all()
{
 set_DQTinfo();
 set_DHTinfo();
 init_Huffman_tables();
 set_numbers_category_and_bitcode();
 precalculate_YCbCr_tables();
 prepare_quant_tables();
}


void SaveJpgFile(char *szBmpFileNameIn, char* szJpgFileNameOut)
{
	char BMP_filename[64];
	char JPG_filename[64];
 	strcpy(BMP_filename, szBmpFileNameIn);
	strcpy(JPG_filename,  szJpgFileNameOut);

	WORD Ximage_original,Yimage_original;	//the original image dimensions,
											// before we made them divisible by 8

	bitstring fillbits; //filling bitstring for the bit alignment of the EOI marker

	load_bitmap(BMP_filename, &Ximage_original, &Yimage_original);
	fp_jpeg_stream=fopen(JPG_filename,"wb");
	init_all();
	SOF0info.width=Ximage_original;
	SOF0info.height=Yimage_original;
	writeword(0xFFD8); //SOI
	write_APP0info();

	write_DQTinfo();
	write_SOF0info();
	write_DHTinfo();
	write_SOSinfo();

	bytenew=0;bytepos=7;
	main_encoder();
	//Do the bit alignment of the EOI marker
	if (bytepos>=0)
	{
		fillbits.length=bytepos+1;
		fillbits.value=(1<<(bytepos+1))-1;
		writebits(fillbits);
	}
	writeword(0xFFD9); //EOI
	free(RGB_buffer); free(category_alloc);free(bitcode_alloc);
	fclose(fp_jpeg_stream);
}






/***************************************************************************/
/*                                                                         */
/* FeedBack Data                                                           */
/*                                                                         */
/***************************************************************************/

//Saving debug information to a log file
void dprintf(const char *fmt, ...)
{
/*
	va_list parms;
	char buf[256];

	// Try to print in the allocated space.
	va_start(parms, fmt);
	vsprintf (buf, fmt, parms);
	va_end(parms);

	// Write the information out to a txt file
	FILE *fp = fopen("output.txt", "a+");
	fprintf(fp, "%s", buf);
	fclose(fp);
*/
}// End dprintf(..)



/***************************************************************************/
/*                                                                         */
/* Entry Point                                                             */
/*                                                                         */
/***************************************************************************/


void pause(int dur)
{
	int temp=time(NULL)+dur;
  while(temp>time(NULL));
  //sleep(5);
}

int main(int argc, char *argv[])
{
	char *input_file, *output_file;

	if (argc < 3) {
        printf("Usage: %s <scalefactor> <input.bmp> [<output.jpg>]\n", argv[0]);
        return 2;
  }
	scalefactor = atoi(argv[1]);
	input_file = argv[2];
	if (argv[3] != NULL)
		output_file = argv[3];
	else{
		output_file = (char *) malloc(8 * sizeof(char));
		strcpy(output_file, "out.jpg");
	}
	//size_t start = clock();
	clock_t tStart = clock();
	//start = clock();
	// Create a jpg from a bmp
	SaveJpgFile(input_file, output_file);
	// Create a bmp from a jpg
	//ConvertJpgFile("smiley.jpg", "smiley.bmp");

	//ConvertJpgFile("imageJPEG3_1.jpg", "imageJPEG3_1.bmp");
	//ConvertJpgFile("imageJPEG3_2.jpg", "imageJPEG3_2.bmp");
	//ConvertJpgFile("test.jpg", "test.bmp");
	//ConvertJpgFile("cross.jpg", "cross.bmp");
	clock_t tstop = clock();
  std::cout << "Finished encode on the whole image in " << ((tstop - tStart)/(1.0*CLOCKS_PER_SEC)) << " s." << std::endl;

	return 0;
}// End WinMain(..)
