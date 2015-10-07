#!/bin/bash

# run-apk-adb.sh
# Run on host
# Description

su -c 'echo energy-lock > /sys/power/wake_lock'

if [ -z $1 ]; then
  echo "Please specify a name for the test"
  su -c 'echo energy-lock > /sys/power/wake_unlock'
  exit 1
fi

DIR=/sdcard/test/"$1"
PACKAGE="com.google.android.gm"
ACTIVITY="ConversationListActivityGmail"

su -c 'setenforce 0'
mkdir -p "$DIR"
rm "$DIR/*"
#su -c "set `ps | grep zygote` ; strace -p $2 -ff -tt -T -s 500 -o \"$DIR/strace\""
PID=$(echo `ps | grep zygote` | cut -d' ' -f2)
su -c "strace -p $PID -q -ff -tt -T -s 500 -o \"$DIR/strace\"" &
am start -n $PACKAGE"/"$PACKAGE"."$ACTIVITY
sleep 15
am force-stop $PACKAGE
am force-stop $PACKAGE
su -c 'killall strace'

su -c 'echo energy-lock > /sys/power/wake_unlock'
