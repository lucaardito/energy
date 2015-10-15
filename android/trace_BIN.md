# Trace system calls for binary
## Setup the toolchain
Compiling *.c* files for Android requires to build the binary for the target architecture (ARM in our case). To speedup the process, cross-compilation is widely used.

This is the sequence to follow to obtain a configuration already compatible with the provided scripts:
- Download Android NDK
- Extract NDK in `/opt/android-ndk`
- run `/opt/android-ndk/build/tools/make-standalone-toolchain.sh --toolchain=arm-linux-androideabi-4.8 --system=linux-x86_64 --install-dir=/opt/android-toolchain --ndk-dir=/opt/android-ndk`
- Compile with `/opt/android-toolchain/bin/arm-linux-androideabi-gcc -FPIE -pie`. PIE flag is mandatory from Android 4.1 (API 16).

[Source](https://developer.android.com/ndk/guides/standalone_toolchain.html)

## Install binary on device
Since the */sdcard* partition has the *noexec* mount flag, it is not possible to set the execution bit for regular files. Therefore the */system* partition is used.

The */system* partition is normally not writable, but with superuser permission is possible to remount the partition in read-write mode. Now it is possible to place the binary in the */system/bin* folder and make it executable. This directory is already in the **path** environmental variable, hence no further actions are required to run the binary system-wide.

The [energy-install.sh](./energy-install.sh) script is a sample. It performs all the operations described before. By default this script pushes the binary in `/system/bin/energy-test`

## Run tests
Use the [run-energy-bin-adb.sh](./run-energy-bin-adb.sh) script on a PC or use the [energy-run-standalone](./energy-run-standalone) script on the device.

This scripts use a *wakelock* in order to wake up the the CPU and keep it awake to complete the test. Without the wakelock the program stops the execution until the device is woken up. At the end, the strace trace is written to a text file and optionally pulled.

## Notes
* Running commands through **adb over wifi** implies a little overhead to power the wireless interface. Actually this could be necessary if the device is not working properly with the USB cable.
* It is necessary to perform the same tests using longer *sleep()* in order to discover other possible power behavior.
