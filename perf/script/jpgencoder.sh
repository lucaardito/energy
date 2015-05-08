#!/bin/bash

#Checking the presence of input parameter (at least)
if [ $# -lt 1 ]
  then
  echo "Usage: jpegencoder.sh <input.jpeg> [<output.bmp>]"
  exit
fi

#Checking the existence of input file
if [ ! -f $1 ]
  then
  echo "Unable to open input file"
  exit
fi

#Recording cpu-clock and page-faults for the decoding operation
# for 3 different level of compression: 20, 40 and 80
comp=20
for (( i=0 ; i<3 ; i++))
do
  ./script/perf_record.sh "./bin/jpgencoder $comp $1 ./output/out.jpg" "./data" "jpgencoder$comp"
  comp=$(($comp * 2))
done
