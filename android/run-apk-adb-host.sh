#!/bin/bash

# run-apk-adb.sh
# Run on host
# Trace system calls of a running application (APK)

ADB=/opt/android-sdk/platform-tools/adb
SCRIPT="run-apk-adb-device2.sh"

if [[ -z $1 ]]; then
  echo "Please specify the name of the test (a directory with the results will be created)"
  exit 1
fi
$ADB push $SCRIPT /sdcard/
$ADB shell sh /sdcard/$SCRIPT "$1"
rm -rf "./data/$1"
mkdir -p "./data/$1"
sleep 8
$ADB pull "/sdcard/test/$1" "./data/$1"
