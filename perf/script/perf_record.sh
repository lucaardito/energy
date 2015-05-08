#!/bin/bash

# $1 = binary to execute
# $2 = output data folder
# $3 = output data name

i=1
argv=()
for arg in "$@"
do
  argv[$i]="$arg"
  i=$((i + 1))
done

perf record -e cpu-clock:u -g -o ${argv[2]}/${argv[3]}.data ${argv[1]}
perf script -i ${argv[2]}/${argv[3]}.data | ./script/stackcollapse-perf.pl > ${argv[2]}/${argv[3]}.stacks-folded
perf report -n --stdio -g fractal,0.5,callee,function -I -i ${argv[2]}/${argv[3]}.data > ${argv[2]}/${argv[3]}.txt # -U: Only display entries resolved to a symbol.
./script/flamegraph.pl ${argv[2]}/${argv[3]}.stacks-folded > ${argv[2]}/${argv[3]}.svg
