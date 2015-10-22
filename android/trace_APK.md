# Tracing system calls for APKs
Profiling the power consumption of system calls requires firstly to define with precision which are the system calls invoked by a specific program. On Android OS, it is possible to use **strace**, an open-source program that is almost a standard in Unix-like operating systems. This tool will be discussed later.

In the Android environment, applications are started by forking the zygote process. This means that it possible to trace the system calls for initialization and execution by tracing the zygote process and following its child processes.
To achieve this result, strace provide the *-ff* parameter in order to save the trace of each thread in a different file:

```shell
su -c 'setenforce 0'
PID=$(echo `ps | grep zygote` | cut -d' ' -f2)
su -c "strace -p $PID -q -ff -tt -T -s 500 -o \"/sdcard/test/strace\""
```
[Source](http://stackoverflow.com/questions/12166917/android-how-to-strace-an-app-using-adb-shell-am-start)

An example of the script is [run-apk-adb-device.sh](./run-apk-adb-device.sh).

> This approach, however, does not show the system calls of processes and thread started by any application [VERIFY THIS BEHAVIOR].
The other approach consist simply to attach strace to the desired application. A sample of this kind of script is [run-apk-adb-device2.sh](./run-apk-adb-device2.sh).

In order to maintain the same conditions for each execution of the application, it is suggested to script the actions to perform. The *adb* tool provide a wide range of possibility in order to achieve this result. For example, running `am start` from the *adb shell* will launch a specific activity, while `am force-stop` closes the application.

## strace
**strace** is a diagnostic, debugging and instructional userspace utility for Linux. It is used to monitor interactions between processes and the Linux kernel, which include system calls, signal deliveries, and changes of process state. The operation of strace is made possible by the kernel feature known as ptrace.

It gives a wide list of parameters

PID and TID

It is important to stress that the use of strace has an heavy impact on the performance of the application. It uses the ptrace() debugging interface, which operates by pausing the target process for each syscall so that the debugger can read the actual state. This operation is done twice: when the syscall begins and when it ends. This means strace pauses the application twice for each syscall, and context-switches each time between the application and strace. For this reason, any timing information may also be so distorted as to be misleading.

## Performing statistics
The analysis and interpretation of acquired data is the main objective of this thesis. Particular attention will be given to the most frequents or longest system calls, that is all those functions that have an important time slice in the application life cycle. This is due to the fact that preceding studies already demonstrated that the power spent is strictly connected with the time.

In order to help with the analysis, the [report-strace.sh](./report-strace.sh) script can be used. This script count the frequency of the system calls for each thread and for the global process. It also shows the total duration for each kind of system call (per-thread).

Simple results of this analysis can be found in the [data section](./data/README.md).

## adb

#### Emulate touches
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
