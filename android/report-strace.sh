#!/bin/bash

# report-strace.sh
# Run on host
# Process strace logs to count number the number of invocation for each system call and execution times (globally and per-thread)

if [[ -z $1 ]]; then
  echo "Please specify the directory"
  exit 1
fi

DIR="./data/$1/*"
REPORT="./data/report-$1.txt"

declare -A globsyscalls # associative array
declare -A globmaxtime
declare -A globmintime
declare -A globtottime

function elapsed_time {
  sed -r -n -e '1 s/^([^a-z]{15})[ ].*/Begin: \1/p ; $ s/^([^a-z]{15})[ ].*/End:   \1/p' "$1" >> $REPORT
  #var=$(sed -r -n -e '1 s/^([^a-z]{15})[ ].*/\1/p ; $ s/^([^a-z]{15})[ ].*/\1/p' "$1")
  #IFS=' ' read b e <<< $var
  #echo "Begin: $b End: $e" >> $REPORT
}

# Count syscall frequency and time spent in execution
function process_file {
  echo "Processing $(basename $1)" >> $REPORT
  declare -A syscalls
  declare -A stime
  while IFS=$'\t' read -r utime syscall st
  do
    ((syscalls[$syscall]++))
    stime[$syscall]=$(bc <<< "${stime[$syscall]:-0} + $st")
    ((globsyscalls[$syscall]++))
    if (( $(bc <<< "$st > ${globmaxtime[$syscall]:-0}") )); then
      globmaxtime[$syscall]=$st
    fi
    if (( $(bc <<< "$st < ${globmintime[$syscall]:-2147483647}") )); then
      globmintime[$syscall]=$st
    fi
    globtottime[$syscall]=$(bc <<< "${globtottime[$syscall]:-0} + $st")
  done < <(sed -r -n -e 's/^([^a-z]{15})[ ]([a-z0-9_-]*).*<([0-9.]*\.[0-9]*)>$/\1\t\2\t\3/p' "$1") # Using regexp to get invocation time, syscall name and execution time
  # Calculating total time
  for key in "${!syscalls[@]}"
  do
    stot=$(awk "BEGIN {print $stot+${stime[$key]}; exit}")
  done
  # Writing to file the total for the file
  for key in "${!syscalls[@]}"
  do
    echo -e "$key\t${syscalls[$key]}\t${stime[$key]}"
  done | LC_ALL="C" sort -rg -k3 >> $REPORT
  echo "System call total time: $stot" >> $REPORT
  elapsed_time "$1"
  echo "" >> $REPORT
  syscalls=
  ktime=
  stot=
}

echo -n "" > $REPORT

for f in $DIR
do
  process_file "$f"
done

echo "*** TOTAL ***" >> $REPORT

echo "* Frequency *" >> $REPORT
for key in "${!globsyscalls[@]}"
do
  echo -e "$key\t${globsyscalls[$key]}"
done | sort -rn -k2  >> $REPORT

echo -e "\n*  Length  *" >> $REPORT
for key in "${!globsyscalls[@]}"
do
  echo -e "$key\t${globmintime[$key]}\t${globmaxtime[$key]}\t${globtottime[$key]}"
done | LC_ALL="C" sort -rg -k2  >> $REPORT
