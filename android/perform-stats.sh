#!/bin/bash

#

if [[ -z $1 ]]; then
  echo "Please specify the directory"
  exit 1
fi

DIR="./data/$1/*"

function process_file {
  echo "Processing $(basename $1)" >> report.txt
  declare -A syscalls
  while read line
  do
    IFS=$'\t' read -r utime syscall ktime < <(echo $line | sed -r -n -e 's/^([^a-z]{15})[ ]([a-z0-9_-]*)[^<]*<(.*)>$/\1\t\2\t\3/p')
    if ! [[ -z $syscall ]]; then
      ((syscalls[$syscall]++))
    fi
  done < "$1"
  for key in "${!syscalls[@]}"
  do
    echo -e "$key\t${syscalls[$key]}" >> report.txt
  done
  syscalls=
}

echo "" > report.txt

for f in $DIR
do
  process_file "$f"
done
