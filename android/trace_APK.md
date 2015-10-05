
# Tracing APKs
Android apps are actually started by forking the zygote process, so it is possible to trace the application initialization by tracing the zygote process and following child processes ('-f'):

```shell
su
setenforce 0  # In Android 4.3 and later, if SELinux is enabled, strace will fail with "strace: wait: Permission denied"
set `ps | grep zygote` ; strace -p $2 -ff -tt -T -s 500 -o /sdcard/test/strace.txt
```
[Source](http://stackoverflow.com/questions/12166917/android-how-to-strace-an-app-using-adb-shell-am-start)

## Pulling results
`adb pull /sdcard/test .`

## Performing statistic
What are relevant data?

## Notes
- tracing overhead (tracing + writing on files)
