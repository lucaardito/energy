#!/bin/bash

# perform-stats.sh
# Run on host
# Process strace logs to count number the number of invocation for each system call (globally and per-thread)

if [[ -z $1 ]]; then
  echo "Please specify the directory"
  exit 1
fi

DIR="./data/$1/*"
REPORT="./data/report-$1.txt"

declare -A globsyscalls # associative array

function process_file {
  echo "Processing $(basename $1)" >> $REPORT
  declare -A syscalls
  while read line
  do
    # Saving into variables useful information (invocation time, syscall name and time spent in kernel space)
    IFS=$'\t' read -r utime syscall ktime < <(echo $line | sed -r -n -e 's/^([^a-z]{15})[ ]([a-z0-9_-]*)[^<]*<(.*)>$/\1\t\2\t\3/p')
    # Ignoring non-matching lines
    if ! [[ -z $syscall ]]; then
      ((syscalls[$syscall]++))
      ((globsyscalls[$syscall]++))
    fi
  done < "$1"
  # Writing to file the total for the file
  for key in "${!syscalls[@]}"
  do
    echo -e "$key\t${syscalls[$key]}" >> $REPORT
  done
  syscalls=
}

echo -n "" > $REPORT

for f in $DIR
do
  process_file "$f"
done

echo -e "\n***TOTAL***" >> $REPORT

for key in "${!globsyscalls[@]}"
do
  echo -e "$key\t${globsyscalls[$key]}" >> $REPORT
done
