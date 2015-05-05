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
  perf record -e cpu-clock,faults -g -o ../data/jpgencoder$comp.data ../bin/jpgencoder $comp $1
  perf script -i ../data/jpgencoder$comp.data | ./stackcollapse-perf.pl > ../data/encoder${comp}.stacks-folded
  ./flamegraph.pl ../data/encoder${comp}.stacks-folded > ../data/jpegencoder$comp.svg
  comp=$(($comp * 2))
done

#Looping on decoding to collect more samples.
#It seems that --append option is not working
#for (( i=0 ; i<4; i++))
#do
#  perf record -e cpu-clock,faults --append -o ../data/jpgdecoder.data ../bin/jpgdecoder $1
#done
