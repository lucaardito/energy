# Tracing system calls for APKs
Android apps are started by forking the zygote process, so it is possible to trace the system calls for initialization and execution by tracing the zygote process and following child processes.
To do this, simply start strace with the *-ff* parameter in order to save the trace of each thread in a different file:

```shell
su -c 'setenforce 0'
PID=$(echo `ps | grep zygote` | cut -d' ' -f2)
su -c "strace -p $PID -q -ff -tt -T -s 500 -o \"/sdcard/test/strace\""
```
[Source](http://stackoverflow.com/questions/12166917/android-how-to-strace-an-app-using-adb-shell-am-start)

In order to maintain the same conditions for each execution of the application, it is suggested to use a script. `am start` can be used to launch a package and activity, while `am force-stop` closes the application.

A sample of a final form of the script is [run-apk-adb-device.sh](./run-apk-adb-device.sh)

## Performing statistic
We need to trace most frequent or longest system calls. In order to help with the analysis, the [report-strace.sh](./report-strace.sh) script can be used.
The script count the frequency of the system calls for each thread and for the global process. It also shows the total duration for each kind of system call (per-thread).

Simple results of this analysis can be found in the [data section](./data/README.md).

## Notes
- tracing overhead (tracing + writing on files)
- a wakelock is used because the screen is kept off

---

### Emulate touches
To discover the event to reproduce, it is necessary to start logging:

`adb shell getevent | grep event2`

Then reproduce the desired motion event, a touch in our case, and convert all values from hex in dump to decimal values.

To send the event

```shell
adb shell sendevent /dev/input/event2 3 57 23710
adb shell sendevent /dev/input/event2 3 53 329
adb shell sendevent /dev/input/event2 3 54 1183
adb shell sendevent /dev/input/event2 3 52 0
adb shell sendevent /dev/input/event2 0 0 0
adb shell sendevent /dev/input/event2 3 57 4294967295
adb shell sendevent /dev/input/event2 0 0 0
```

> I figured from posts in linked forum that line 2 and 3 are setting X and Y position the next 2 lines are touch press and the bottom 2 lines are touch release, I havent figured out what the first line does yet but it is needed for it to work.

[Source](http://stackoverflow.com/questions/8647826/simulating-touch-using-adb)

---

Tap X,Y position:

`adb shell input tap 500 1450`

To find the exact X,Y position you want to Tap go to:
Settings > Developer Options > Check the option POINTER SLOCATION

[Source](http://stackoverflow.com/questions/7789826/adb-shell-input-events)
