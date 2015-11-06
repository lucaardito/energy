#!/bin/bash

# run-apk-adb.sh
# Run on host
# Trace system calls of a running application (APK)

#ADB=/opt/android-sdk/platform-tools/adb
ADB=adb
SCRIPT="run-apk-adb-device3.sh"

$ADB push $SCRIPT /sdcard/
$ADB shell sh /sdcard/$SCRIPT "$1"
