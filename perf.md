# Guide to perf to identify and analyze "hot spots" in a program
Perf is a profiler tool for Linux 2.6+ based systems that abstracts away CPU hardware differences in Linux performance measurements and presents a simple commandline interface.
## Events
The perf tool supports a list of measurable events. The tool and underlying kernel interface can measure events coming from different sources. For instance, some event are pure kernel counters, in this case they are called **software events**.
### [cpu-clock event] [1]
The cpu-clock event measures the passage of time. It uses the Linux CPU clock as the timing source. Analyzing the execution time is a good starting point for performance analysis.
To see the CPU clocks for a given program, run the following command
```bash
perf stat -e cpu-clock "/path/to/program"
```
### [page-faults] [1]
```bash
perf stat -e faults "/path/to/program"
```
## [Performance analysis] [1]
The code regions which take the most execution time are called hot spots. The hot spots are the best places to tune and optimize because a little bit of effort on making a hot spot faster can have a big pay-off.

We at least need to know if the program is CPU-bound (does a lot of computation) or is memory-bound (needs to read/write a lot of data in memory). We also need to know where the events are occuring in the program. If the events correlate with a known hot spot, then we may have found a real performance issue and need to fix it.

### [Collect profile data] [1]
A profile is a table (or annotated code listing) that shows us execution time hot spots and/or the code regions where certain hardware or software events are occuring. 
To collect this data, run the *perf record* command. This command runs the program to be analyzed, collects profile data and stores the profile data into a file named perf.data (the default file name). In order to change the output filename, use the *-o* option
```bash
perf record -e cpu-clock,faults "/path/to/program"
```
It is also possible to change the **sampling frequency** with the *-f* option. Increasing this value (default is 4000), can produce more accurate values, but can modify the actual standalone behavior of the application program (especially on single core CPU).

### [Profile analysis] [1]
The *perf record* command allow the analisys of previous collected data
```bash
perf report -i "perf.data"
```
The default UI used to represent data is the *TUI* (*Terminal-based User Interface*), which is an interactive textual interface.

There is also the possibility to use the standard output to display the results (there is no interactivity, of course), which is appropriate when redirecting the output to a file or to a script. To enable it, use the *--stdio* option.


[1]: http://sandsoftwaresound.net/perf/perf-tutorial-hot-spots/
