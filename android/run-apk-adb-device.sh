#!/bin/bash

# run-apk-adb.sh
# Run on host
# Trace system calls of a running application (APK)

su -c 'echo energy-lock > /sys/power/wake_lock'

if [ -z $1 ]; then
  echo "Please specify a name for the test"
  su -c 'echo energy-lock > /sys/power/wake_unlock' # Release wakelock before exit
  exit 1
fi

DIR=/sdcard/test/"$1"
PACKAGE="com.google.android.gm"
ACTIVITY="ConversationListActivityGmail"

su -c 'setenforce 0'
mkdir -p "$DIR"
rm -f "$DIR/*"
PID=$(echo `ps | grep zygote` | cut -d' ' -f2)  # zygote process is forked to run application
su -c "strace -p $PID -q -ff -tt -T -s 500 -o \"$DIR/strace\"" &  # Now we are recording the trace
am start -n $PACKAGE"/"$PACKAGE"."$ACTIVITY
sleep 15  # Actually we are performing only a sleep
am force-stop $PACKAGE
am force-stop $PACKAGE  # Stopping again, just to be sure the application is completely closed
su -c 'killall strace'  # strace must be closed

su -c 'echo energy-lock > /sys/power/wake_unlock'
