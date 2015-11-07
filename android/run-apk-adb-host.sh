#!/bin/bash

# run-apk-adb-host.sh
# Run on host
# Push the correct script (that do not run strace) and run it

#ADB=/opt/android-sdk/platform-tools/adb
ADB=adb
SCRIPT="run-apk-adb-device3.sh"

$ADB push $SCRIPT /sdcard/
$ADB shell sh /sdcard/$SCRIPT "$1"
