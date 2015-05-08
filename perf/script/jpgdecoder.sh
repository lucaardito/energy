#!/bin/bash

#Checking the presence of input parameter (at least)
if [ $# -lt 1 ]
  then
  echo "Usage: jpegdecoder.sh <input.jpeg> [<output.bmp>]"
  exit
fi

#Checking the existence of input file
if [ ! -f $1 ]
  then
  echo "Unable to open input file"
  exit
fi

#Recording cpu-clock and page-faults for the decoding operation
./script/perf_record.sh "./bin/jpgdecoder $1 ./output/out.bmp" "./data" "jpgdecoder"

#Looping on decoding to collect more samples.
#It seems that --append option is not working
#for (( i=0 ; i<4; i++))
#do
#  perf record -e cpu-clock,faults --append -o ../data/jpgdecoder.data ../bin/jpgdecoder $1
#done
