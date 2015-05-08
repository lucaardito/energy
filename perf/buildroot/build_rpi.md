I have encountered problems in building the lttng modules with the raspberrypi2_defconfig. The packaged lttng-module version is compatible with Linux 2.6.38 to 3.16, but the defconfig uses 3.18 Linux kernel.

#Instructions
* Download a snapshot
```bash
wget http://buildroot.uclibc.org/downloads/snapshots/buildroot-20150505.tar.bz2
```
The daily snapshot is http://buildroot.uclibc.org/downloads/snapshots/buildroot-snapshot.tar.bz2

* Extract
```bash
tar -xvf buildroot-20150505.tar.bz2
```
* Import default configuration
```bash
cd buildroot
make raspberrypi2_defconfig
```
* Tweak parameters
```bash
make nconfig
```
* Add some default utilities (better to provide the entire image)

* (Add lttng (http://lttng.org/docs/#doc-buildroot))

* Compile the system
```bash
make
```
* Buildroot output is stored in a single directory (output/)

* https://github.com/gamaral/rpi-buildroot
