#!/bin/bash

# run-apk-adb-host.sh
# Run on host
# Push the correct script (that do not run strace) and run it

#ADB=/opt/android-sdk/platform-tools/adb
ADB=adb
SCRIPT_PATH="scripts_device/"
SCRIPT="run-apk-adb-device4.sh"

$ADB push $SCRIPT_PATH$SCRIPT /sdcard/
$ADB shell sh /sdcard/$SCRIPT "$1"
