# Running APKs from shell

## Emulate touches
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
