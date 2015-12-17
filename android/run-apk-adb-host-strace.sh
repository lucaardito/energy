#!/bin/bash

# run-apk-adb-host-strace.sh
# Run on host
# Push the correct script (that run strace) and pull the results in the directory given as first parameter

ADB=/opt/android-sdk/platform-tools/adb
SCRIPT_PATH="scripts_device/"
SCRIPT="run-apk-adb-device2.sh"

if [[ -z $1 ]]; then
  echo "Please specify the name of the test (a directory with the results will be created)"
  exit 1
fi

i=0
while [[ i -lt 10 ]]
do
  $ADB push $SCRIPT_PATH$SCRIPT /sdcard/
  $ADB shell sh /sdcard/$SCRIPT "$1$i"
  rm -rf "./data/$1$i"
  mkdir -p "./data/$1$i"
  $ADB pull "/sdcard/test/$1$i" "./data/$1$i"
  i=$(expr $i + 1)
  sleep 5
done
