Data collected running
```set `ps | grep zygote` ; strace -p $2 -ff -tt -T -s 500 -o /sdcard/test/strace.txt```
and starting Gmail.

Syncronization is disabled and no mail are present.
