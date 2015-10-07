#!/bin/bash

# run-energy-bin-adb.sh
# Run on host
# Run energy test collecting strace data trough adb.
# Wakelock is used in order to perform test with screen off

ADB=/opt/android-sdk/platform-tools/adb

$ADB shell "su -c 'echo energy-lock > /sys/power/wake_lock'"
$ADB shell "strace -C -T -tt -r -D -o /sdcard/trace.txt energy-test"
$ADB pull /sdcard/trace.txt .
$ADB shell "su -c 'echo energy-lock > /sys/power/wake_unlock'"
