#!/bin/bash

if [[ -z $1 ]]; then
  echo "Please specify the input name"
  exit 1
fi

INPUT="./data/report-$1*"

declare -A mincallf
declare -A maxcallf
declare -A avgcallf
declare -A cntcall
declare -A mincallt
declare -A maxcallt
declare -A avgcallt

function process_file {
  while IFS=$'\t' read -r syscall freq
  do
    ((cntcall[$syscall]++))
    avgcallf[$syscall]=$(bc <<< "${avgcallf[$syscall]:-0} + $freq")
    if (( $(bc <<< "$freq > ${maxcallf[$syscall]:-0}") )); then
      maxcallf[$syscall]=$freq
    fi
    if (( $(bc <<< "$freq < ${mincallf[$syscall]:-2147483647}") )); then
      mincallf[$syscall]=$freq
    fi
  done < <(sed -r -n -e '/Frequency/,/Longest/ s/^(.+)\t(.+)$/\1\t\2/p' "$1")

  while IFS=$'\t' read -r syscall freq
  do
    avgcallt[$syscall]=$(bc <<< "${avgcallt[$syscall]:-0} + $freq")
    if (( $(bc <<< "$freq > ${maxcallt[$syscall]:-0}") )); then
      maxcallt[$syscall]=$freq
    fi
    if (( $(bc <<< "$freq < ${mincallt[$syscall]:-2147483647}") )); then
      mincallt[$syscall]=$freq
    fi
  done < <(sed -r -n -e '/Longest/,$ s/^(.+)\t(.+)$/\1\t\2/p' "$1")
}

for f in $INPUT
do
  process_file "$f"
done

for key in "${!cntcall[@]}"
do
  echo -e "\t<tr>"

  echo -e "\t\t<td>$key</td>"
  echo -e "\t\t<td>${mincallf[$key]}</td>"
  echo -e "\t\t<td>${maxcallf[$key]}</td>"
  x=$(bc -l <<< "scale=2;${avgcallf[$key]} / ${cntcall[$key]}")
  x=$(echo $x | sed -e 's/^\./0./')
  echo -e "\t\t<td>$x</td>"

  echo -e "\t\t<td>${mincallt[$key]}</td>"
  echo -e "\t\t<td>${maxcallt[$key]}</td>"
  x=$(bc -l <<< "scale=6;${avgcallt[$key]} / ${cntcall[$key]}")
  x=$(echo $x | sed -e 's/^\./0./')
  echo -e "\t\t<td>$x</td>"
  echo -e "\t</tr>"
done
