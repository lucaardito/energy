# Guide to perf to identify and analyze "hot spots" in a program
Perf is a profiler tool for Linux 2.6+ based systems that abstracts away CPU hardware differences in Linux performance measurements and presents a simple commandline interface.

## [Events] [2]
The perf tool supports a list of measurable events. The tool and underlying kernel interface can measure events coming from different sources. For instance, some event are pure kernel counters, in this case they are called **software events**.

Another source of events is the processor itself and its *Performance Monitoring Unit* (PMU). It provides a list of events to measure micro-architectural events such as the number of cycles, instructions retired, L1 cache misses and so on. Those events are called PMU hardware events or **hardware events** for short. They vary with each processor type and model.

Finally, there are also **tracepoint events** which are implemented by the kernel ftrace infrastructure. Those are only available with the 2.6.3x and newer kernels.

To obtain a list of supported events:
```bash
perf list
```

### [cycle event] [2]
By default, perf uses the cycles event as the sampling event. This is a generic hardware event that is mapped to a hardware-specific PMU event by the kernel.

For Intel, this event does not maintain a constant correlation to time in the presence of CPU frequency scaling. On AMD systems, the event is also subject to frequency scaling. On any Intel or AMD processor, the cycle event does not count when the processor is idle, i.e., when it calls mwait().
```bash
perf stat -e cycles "/path/to/program"
```

### [cpu-clock event] [1]
The cpu-clock event is a software event that measures the passage of time. It uses the Linux CPU clock as the timing source. Analyzing the execution time is a good starting point for performance analysis.
To see the CPU clocks for a given program, run the following command
```bash
perf stat -e cpu-clock "/path/to/program"
```

### page-faults
The page fault event is a software event useful to identify poor performances due to the slow access to the mass memory (data is not loaded in pysical memory)
```bash
perf stat -e faults "/path/to/program"
```

### [Hardware events] [3]
This is a non-complete list of the most common ARMv7 (Cortex-A7) performance events. The table is taken from the ARM Cortex-A7 MPCore Technical Reference Manual.

Event name | ARMv7 Event ID
---------- | --------------
cpu-cycles OR cycles | 0xFF
instructions | 0×08
cache-references | 0×04
cache-misses | 0×03
branch-instructions OR branches | 0x0C
branch-misses | 0×10
bus-cycles | 0x1D
L1-dcache-loads | 0×04
L1-dcache-load-misses | 0×03
L1-dcache-stores | 0×04
L1-dcache-store-misses | 0×03
L1-icache-loads | 0×14
L1-icode-load-misses | 0×01
LLC-loads | 0×16
LLC-load-misses | 0×17
LLC-stores | 0×16
LLC-store-misses | 0×17
dTLB-load-misses | 0×05
dTLB-store-misses | 0×05
iTLB-load-misses | 0×02
branch-loads | 0×12
branch-load-misses | 0×10

In order to measure the number of performance events, just use the *perf record* or *perf stat* with the *-e* option. It is possible to specify both the *event name* or the *raw event ID*.

```bash
perf stat -e cpu-cycles,r010 ./naive
```

## [Performance analysis] [1]
To analyze the performances, it is important to establish the kind of events that are relevant and have a great impact on execution.
For example, the program could be **CPU-bound** (does a lot of computation) or **memory-bound** (needs to read/write a lot of data in memory). More important is to identify where the events are occuring in the program.

The code regions which take the most execution time are called **hot spots**. The hot spots are the best places to tune and optimize because a little bit of effort on making a hot spot faster can have a big pay-off.

### [Collect profile data] [2]
Perf is based on event-based sampling. The period is expressed as the number of occurrences of an event, not the number of timer ticks. A sample is recorded when the sampling counter overflows. When it happens, perf determines what the CPU was doing at the time of the interrupt: it identifies the software component that was interrupted, it captures the CPU core number, program counter and other relevant information, and it writes all of this data to a buffer in the form of a data item called a sample. The buffer is eventually written to the data file.
What gets recorded depends on the type of measurement. This is all specified by the user and the tool, but the key information that is common in all samples is the *instruction pointer*, i.e. where was the program when it was interrupted.

This kind of interrupt-based sampling introduces **skids** on modern processors. That means that the instruction pointer stored in each sample designates the place where the program was interrupted to process the interrupt, not the place where the counter actually overflows, i.e., where it was at the end of the sampling period. In some case, the distance between those two points may be several dozen instructions or more if there were taken branches. When the program cannot make forward progress, those two locations are indeed identical. For this reason, care must be taken when interpreting profiles.

A **profile** is a table (or annotated code listing) that shows execution time hot spots and/or the code regions where certain hardware or software events are occuring.
To collect this data, run the *perf record* command. This command runs the program to be analyzed, collects profile data and stores the profile data into a file named perf.data (the default file name). In order to change the output filename, use the *-o* option
```bash
perf record -e cpu-clock,faults "/path/to/program"
```
It is also possible to change the **sampling frequency** with the *-f* option.
Instead, to specify the **sampling period**, it is possible to use the *-c* option. Modifying these values in order to acquire more samples, can produce more accurate results, but can modify the actual standalone behavior of the application program (especially on single core CPU).

### [Profile analysis] [1]
The *perf report* command allow the analisys of previous recorded data
```bash
perf report -i "perf.data"
```
The default UI used to represent data is the **TUI** (*Terminal-based User Interface*), which is an interactive textual interface.

By default, samples are sorted by functions with the most samples first. It is possible to customize the sorting order and therefore to view the data differently with the *--sort* option.

It is possible to navigate inside the acquired data and see the **annotated code** for each function. Annotated code is disassembled machine code (or surce code, if the program was compiled with debug symbols) that shows time spent on each code region.

There is also the possibility to use the standard output to display the results (without interactivity, of course), which is appropriate when redirecting the output to a file or to a script. To enable it, use the *--stdio* option with the *perf report* or *perf annotate* command.

[1]: http://sandsoftwaresound.net/perf/perf-tutorial-hot-spots/
[2]: https://perf.wiki.kernel.org/index.php/Tutorial
[3]: http://sandsoftwaresound.net/perf/perf-tut-count-hw-events/
