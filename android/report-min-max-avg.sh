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
  #echo "Processing $(basename $1)"
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
  done < <(sed -r -n -e '/Frequency/,/Length/ s/^(.+)\t(.+)$/\1\t\2/p' "$1")

  while IFS=$'\t' read -r syscall minsec maxsec totsec
  do
    avgcallt[$syscall]=$(bc -l <<< "${avgcallt[$syscall]:-0} + $totsec")
    if (( $(bc <<< "$maxsec > ${maxcallt[$syscall]:-0}") )); then
      maxcallt[$syscall]=$maxsec
    fi
    if (( $(bc <<< "$minsec < ${mincallt[$syscall]:-2147483647}") )); then
      mincallt[$syscall]=$minsec
    fi
  done < <(sed -r -n -e '/Length/,$ s/^(.+)\t(.+)\t(.+)\t(.+)$/\1\t\2\t\3\t\4/p' "$1")
}

for f in $INPUT
do
  process_file "$f"
done

for key in "${!cntcall[@]}"
do
  echo -ne "<tr>"

  echo -ne "\t<td>$key</td>"
  echo -ne "\t<td>${mincallf[$key]}</td>"
  echo -ne "\t<td>${maxcallf[$key]}</td>"
  totcallf=${avgcallf[$key]}
  avgcallf[$key]=$(bc -l <<< "scale=2;${avgcallf[$key]} / ${cntcall[$key]}")
  x=$(echo ${avgcallf[$key]} | sed -e 's/^\./0./')
  echo -ne "\t<td>$x</td>"

  echo -ne "\t<td>${mincallt[$key]}</td>"
  echo -ne "\t<td>${maxcallt[$key]}</td>"
  avgcallt[$key]=$(echo $(bc -l <<< "scale=6;${avgcallt[$key]} / $totcallf") | sed -e 's/^\./0./')
  echo -ne "\t<td>$x</td>"
  x=$(echo $(bc -l <<< "scale=6;${avgcallt[$key]} *  ${avgcallf[$key]}") | sed -e 's/^\./0./')
  echo -ne "\t<td>\t$x\t</td>"

  echo -e "\t</tr>"
done | LC_ALL="C" sort -rg -k10
