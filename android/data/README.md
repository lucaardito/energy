# Tests
| Start | End | Description |
| --- | --- | --- |
| gmail-screen0 | gmail-screen9 | Run Gmail with screen ON, wifi active, adb over wifi, sync disabled, no mail present |
| white-screen0 | white-screen9 | Run EnergyWhite screen ON, wifi active, adb over wifi |

# Results
## Gmail
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="3">Longest</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
  </tr>
  <tr>
    <td>mprotect</td>
    <td>10</td>
    <td>37</td>
    <td>23.50</td>
    <td>0.000146</td>
    <td>0.021022</td>
    <td>0.002418</td>
  </tr>
  <tr>
    <td>pwrite</td>
    <td>20</td>
    <td>31</td>
    <td>21.10</td>
    <td>0.000138</td>
    <td>0.007197</td>
    <td>0.001987</td>
  </tr>
  <tr>
    <td>mmap2</td>
    <td>35</td>
    <td>66</td>
    <td>56.10</td>
    <td>0.000371</td>
    <td>0.004830</td>
    <td>0.001936</td>
  </tr>
  <tr>
    <td>restart_syscall</td>
    <td>2</td>
    <td>4</td>
    <td>2.90</td>
    <td>3.842994</td>
    <td>9.397483</td>
    <td>8.665673</td>
  </tr>
  <tr>
    <td>sigaltstack</td>
    <td>5</td>
    <td>13</td>
    <td>9.40</td>
    <td>0.000125</td>
    <td>0.001716</td>
    <td>0.000366</td>
  </tr>
  <tr>
    <td>pread</td>
    <td>23</td>
    <td>57</td>
    <td>40.20</td>
    <td>0.000489</td>
    <td>0.006150</td>
    <td>0.002659</td>
  </tr>
  <tr>
    <td>getpriority</td>
    <td>55</td>
    <td>101</td>
    <td>79.20</td>
    <td>0.000319</td>
    <td>0.008639</td>
    <td>0.003158</td>
  </tr>
  <tr>
    <td>clock_gettime</td>
    <td>1133</td>
    <td>2760</td>
    <td>2032.30</td>
    <td>0.007408</td>
    <td>0.171895</td>
    <td>0.051800</td>
  </tr>
  <tr>
    <td>fchmodat</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000053</td>
    <td>0.000273</td>
    <td>0.000139</td>
  </tr>
  <tr>
    <td>pselect6</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.076822</td>
    <td>0.574914</td>
    <td>0.339859</td>
  </tr>
  <tr>
    <td>clone</td>
    <td>2</td>
    <td>9</td>
    <td>5.60</td>
    <td>0.001080</td>
    <td>0.026230</td>
    <td>0.005055</td>
  </tr>
  <tr>
    <td>fcntl64</td>
    <td>56</td>
    <td>94</td>
    <td>78.60</td>
    <td>0.001297</td>
    <td>0.010029</td>
    <td>0.006111</td>
  </tr>
  <tr>
    <td>fsync</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.006513</td>
    <td>0.013021</td>
    <td>0.009062</td>
  </tr>
  <tr>
    <td>rt_sigprocmask</td>
    <td>25</td>
    <td>42</td>
    <td>40.20</td>
    <td>0.000124</td>
    <td>0.000779</td>
    <td>0.000311</td>
  </tr>
  <tr>
    <td>epoll_pwait</td>
    <td>161</td>
    <td>283</td>
    <td>217.10</td>
    <td>1.949621</td>
    <td>4.238300</td>
    <td>3.350978</td>
  </tr>
  <tr>
    <td>newfstatat</td>
    <td>4</td>
    <td>16</td>
    <td>13.20</td>
    <td>0.000152</td>
    <td>0.011845</td>
    <td>0.003143</td>
  </tr>
  <tr>
    <td>write</td>
    <td>233</td>
    <td>590</td>
    <td>375.40</td>
    <td>0.004377</td>
    <td>0.078820</td>
    <td>0.035859</td>
  </tr>
  <tr>
    <td>epoll_ctl</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000027</td>
    <td>0.000168</td>
    <td>0.000083</td>
  </tr>
  <tr>
    <td>setpriority</td>
    <td>8</td>
    <td>19</td>
    <td>16.10</td>
    <td>0.000203</td>
    <td>0.012566</td>
    <td>0.001679</td>
  </tr>
  <tr>
    <td>recvfrom</td>
    <td>114</td>
    <td>269</td>
    <td>193.40</td>
    <td>0.001582</td>
    <td>0.099773</td>
    <td>0.013886</td>
  </tr>
  <tr>
    <td>munmap</td>
    <td>32</td>
    <td>63</td>
    <td>51.10</td>
    <td>0.000250</td>
    <td>0.006052</td>
    <td>0.003142</td>
  </tr>
  <tr>
    <td>faccessat</td>
    <td>8</td>
    <td>16</td>
    <td>13.30</td>
    <td>0.000222</td>
    <td>0.005297</td>
    <td>0.001604</td>
  </tr>
  <tr>
    <td>getuid32</td>
    <td>97</td>
    <td>177</td>
    <td>146.00</td>
    <td>0.001441</td>
    <td>0.029453</td>
    <td>0.010713</td>
  </tr>
  <tr>
    <td>gettimeofday</td>
    <td>228</td>
    <td>272</td>
    <td>256.90</td>
    <td>0.004978</td>
    <td>0.055956</td>
    <td>0.013724</td>
  </tr>
  <tr>
    <td>openat</td>
    <td>26</td>
    <td>44</td>
    <td>37.60</td>
    <td>0.000342</td>
    <td>0.005287</td>
    <td>0.002450</td>
  </tr>
  <tr>
    <td>madvise</td>
    <td>131</td>
    <td>299</td>
    <td>249.80</td>
    <td>0.000306</td>
    <td>0.010951</td>
    <td>0.003228</td>
  </tr>
  <tr>
    <td>fdatasync</td>
    <td>1</td>
    <td>3</td>
    <td>1.20</td>
    <td>0.005231</td>
    <td>0.015527</td>
    <td>0.011054</td>
  </tr>
  <tr>
    <td>set_tid_address</td>
    <td>3</td>
    <td>4</td>
    <td>3.80</td>
    <td>0.000098</td>
    <td>0.000236</td>
    <td>0.000164</td>
  </tr>
  <tr>
    <td>ftruncate64</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000109</td>
    <td>0.000109</td>
    <td>0.000109</td>
  </tr>
  <tr>
    <td>sched_yield</td>
    <td>14</td>
    <td>208</td>
    <td>129.60</td>
    <td>0.000026</td>
    <td>0.002601</td>
    <td>0.000682</td>
  </tr>
  <tr>
    <td>ioctl</td>
    <td>798</td>
    <td>1373</td>
    <td>1087.30</td>
    <td>1.462750</td>
    <td>2.653122</td>
    <td>2.206116</td>
  </tr>
  <tr>
    <td>futex</td>
    <td>1083</td>
    <td>2043</td>
    <td>1492.20</td>
    <td>1.293392</td>
    <td>9.997884</td>
    <td>3.618772</td>
  </tr>
  <tr>
    <td>dup</td>
    <td>88</td>
    <td>202</td>
    <td>146.70</td>
    <td>0.000207</td>
    <td>0.005177</td>
    <td>0.000906</td>
  </tr>
  <tr>
    <td>close</td>
    <td>192</td>
    <td>385</td>
    <td>287.40</td>
    <td>0.000642</td>
    <td>0.014263</td>
    <td>0.003218</td>
  </tr>
  <tr>
    <td>renameat</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000094</td>
    <td>0.000406</td>
    <td>0.000192</td>
  </tr>
  <tr>
    <td>geteuid32</td>
    <td>1</td>
    <td>5</td>
    <td>3.80</td>
    <td>0.000103</td>
    <td>0.000617</td>
    <td>0.000270</td>
  </tr>
  <tr>
    <td>fstat64</td>
    <td>8</td>
    <td>32</td>
    <td>24.80</td>
    <td>0.000263</td>
    <td>0.007958</td>
    <td>0.002474</td>
  </tr>
  <tr>
    <td>nanosleep</td>
    <td>1</td>
    <td>3</td>
    <td>1.40</td>
    <td>0.001600</td>
    <td>0.003104</td>
    <td>0.001916</td>
  </tr>
  <tr>
    <td>unlinkat</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000146</td>
    <td>0.000380</td>
    <td>0.000244</td>
  </tr>
  <tr>
    <td>eventfd2</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000024</td>
    <td>0.000132</td>
    <td>0.000056</td>
  </tr>
  <tr>
    <td>writev</td>
    <td>8</td>
    <td>14</td>
    <td>12.00</td>
    <td>0.000191</td>
    <td>0.007569</td>
    <td>0.002096</td>
  </tr>
  <tr>
    <td>epoll_create1</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000024</td>
    <td>0.000131</td>
    <td>0.000056</td>
  </tr>
  <tr>
    <td>read</td>
    <td>88</td>
    <td>211</td>
    <td>151.30</td>
    <td>0.000373</td>
    <td>0.030345</td>
    <td>0.007597</td>
  </tr>
  <tr>
    <td>prctl</td>
    <td>152</td>
    <td>399</td>
    <td>240.00</td>
    <td>0.000857</td>
    <td>0.103392</td>
    <td>0.023809</td>
  </tr>
  <tr>
    <td>getsockopt</td>
    <td>1</td>
    <td>3</td>
    <td>2.00</td>
    <td>0.000029</td>
    <td>0.000232</td>
    <td>0.000138</td>
  </tr>
</table>

## White
<table>
  <tr>
    <td></td>
    <td colspan="3">Frequency</td>
    <td colspan="3">Longest</td>
  </tr>
  <tr>
    <td>System call</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
    <td>min</td>
    <td>max</td>
    <td>avg</td>
  </tr>
  <tr>
    <td>mprotect</td>
    <td>4</td>
    <td>4</td>
    <td>4.00</td>
    <td>0.000031</td>
    <td>0.000848</td>
    <td>0.000365</td>
  </tr>
  <tr>
    <td>mmap2</td>
    <td>3</td>
    <td>3</td>
    <td>3.00</td>
    <td>0.000120</td>
    <td>0.003860</td>
    <td>0.000953</td>
  </tr>
  <tr>
    <td>sigaltstack</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000026</td>
    <td>0.001281</td>
    <td>0.000290</td>
  </tr>
  <tr>
    <td>getpriority</td>
    <td>2</td>
    <td>3</td>
    <td>2.60</td>
    <td>0.000111</td>
    <td>0.000599</td>
    <td>0.000231</td>
  </tr>
  <tr>
    <td>clock_gettime</td>
    <td>6</td>
    <td>6</td>
    <td>6.00</td>
    <td>0.000049</td>
    <td>0.002519</td>
    <td>0.000586</td>
  </tr>
  <tr>
    <td>clone</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000080</td>
    <td>0.000542</td>
    <td>0.000377</td>
  </tr>
  <tr>
    <td>epoll_pwait</td>
    <td>3</td>
    <td>3</td>
    <td>3.00</td>
    <td>0.370851</td>
    <td>0.602746</td>
    <td>0.506074</td>
  </tr>
  <tr>
    <td>write</td>
    <td>5</td>
    <td>8</td>
    <td>6.80</td>
    <td>0.000129</td>
    <td>0.015051</td>
    <td>0.005302</td>
  </tr>
  <tr>
    <td>setpriority</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000028</td>
    <td>0.000139</td>
    <td>0.000062</td>
  </tr>
  <tr>
    <td>getuid32</td>
    <td>2</td>
    <td>3</td>
    <td>2.60</td>
    <td>0.000021</td>
    <td>0.000237</td>
    <td>0.000090</td>
  </tr>
  <tr>
    <td>openat</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000043</td>
    <td>0.000060</td>
    <td>0.000052</td>
  </tr>
  <tr>
    <td>madvise</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000039</td>
    <td>0.000201</td>
    <td>0.000070</td>
  </tr>
  <tr>
    <td>ioctl</td>
    <td>2</td>
    <td>5</td>
    <td>3.80</td>
    <td>0.371700</td>
    <td>0.548940</td>
    <td>0.469453</td>
  </tr>
  <tr>
    <td>futex</td>
    <td>4</td>
    <td>13</td>
    <td>7.60</td>
    <td>0.000135</td>
    <td>0.011290</td>
    <td>0.002314</td>
  </tr>
  <tr>
    <td>close</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000024</td>
    <td>0.000032</td>
    <td>0.000029</td>
  </tr>
  <tr>
    <td>read</td>
    <td>1</td>
    <td>1</td>
    <td>1.00</td>
    <td>0.000022</td>
    <td>0.034426</td>
    <td>0.003663</td>
  </tr>
  <tr>
    <td>prctl</td>
    <td>4</td>
    <td>10</td>
    <td>7.60</td>
    <td>0.000111</td>
    <td>0.003480</td>
    <td>0.000636</td>
  </tr>
</table>

# Common system calls
## Frequency (alphabetical order)
* **clock_gettime**
* **epoll_pwait**
* **futex**
* **getuid32**
* **ioctl**
* **prctl**
* **write**

## Longest (alphabetical order)
* **clock_gettime**
* **clone**
* **epoll_pwait**
* **futex**
* **getuid32**
* **ioctl**
* **mprotect**
* **prctl**
* **read**
* **write**

# [Description of system calls](http://linux.die.net/)
## clock_gettime()
The function clock_gettime() retrieve the time of the specified clock.

A clock may be system-wide and hence visible for all processes, or per-process if it measures time only within a single process.

All implementations support the system-wide real-time clock, which is identified by CLOCK_REALTIME. Its time represents seconds and nanoseconds since the Epoch. When its time is changed, timers for a relative interval are unaffected, but timers for an absolute point in time are affected.

More clocks may be implemented. The interpretation of the corresponding time values and the effect on timers is unspecified.

## clone()
clone() creates a new process, in a manner similar to fork(2). It is actually a library function layered on top of the underlying clone() system call, hereinafter referred to as sys_clone. A description of sys_clone is given toward the end of this page.

Unlike fork(2), these calls allow the child process to share parts of its execution context with the calling process, such as the memory space, the table of file descriptors, and the table of signal handlers. (Note that on this description, "calling process" normally corresponds to "parent process".)

The main use of clone() is to implement threads: multiple threads of control in a program that run concurrently in a shared memory space.

When the child process is created with clone(), it executes the function fn(arg). (This differs from fork(2), where execution continues in the child from the point of the fork(2) call.) The fn argument is a pointer to a function that is called by the child process at the beginning of its execution. The arg argument is passed to the fn function.

When the fn(arg) function application returns, the child process terminates. The integer returned by fn is the exit code for the child process. The child process may also terminate explicitly by calling exit(2) or after receiving a fatal signal.

The child_stack argument specifies the location of the stack used by the child process. Since the child and calling process may share memory, it is not possible for the child process to execute in the same stack as the calling process. The calling process must therefore set up memory space for the child stack and pass a pointer to this space to clone(). Stacks grow downward on all processors that run Linux (except the HP PA processors), so child_stack usually points to the topmost address of the memory space set up for the child stack.

The low byte of flags contains the number of the termination signal sent to the parent when the child dies. If this signal is specified as anything other than SIGCHLD, then the parent process must specify the \_\_WALL or \_\_WCLONE options when waiting for the child with wait(2). If no signal is specified, then the parent process is not signaled when the child terminates.

## epoll_pwait()
The epoll_wait() system call waits for events on the epoll(7) instance referred to by the file descriptor epfd. The memory area pointed to by events will contain the events that will be available for the caller. Up to maxevents are returned by epoll_wait(). The maxevents argument must be greater than zero.

The timeout argument specifies the minimum number of milliseconds that epoll_wait() will block. (This interval will be rounded up to the system clock granularity, and kernel scheduling delays mean that the blocking interval may overrun by a small amount.) Specifying a timeout of -1 causes epoll_wait() to block indefinitely, while specifying a timeout equal to zero cause epoll_wait() to return immediately, even if no events are available.

epoll_pwait() allows an application to safely wait until either a file descriptor becomes ready or until a signal is caught.

If the sigmask argument is NULL, epoll_pwait() is equivalent to epoll_wait().

## futex()
The futex() system call provides a method for a program to wait for a value at a given address to change, and a method to wake up anyone waiting on a particular address (while the addresses for the same memory in separate processes may not be equal, the kernel maps them internally so the same memory mapped in different locations will correspond for futex() calls). This system call is typically used to implement the contended case of a lock in shared memory.

## getuid32()
getuid() returns the real user ID of the calling process.

The original Linux getuid() and geteuid() system calls supported only 16-bit user IDs. Subsequently, Linux 2.4 added getuid32() and geteuid32(), supporting 32-bit IDs.

## ioctl()
The ioctl() function manipulates the underlying device parameters of special files. In particular, many operating characteristics of character special files (e.g., terminals) may be controlled with ioctl() requests. The argument d must be an open file descriptor.

The second argument is a device-dependent request code. The third argument is an untyped pointer to memory. It's traditionally char \*argp (from the days before void \* was valid C), and will be so named for this discussion.

An ioctl() request has encoded in it whether the argument is an in parameter or out parameter, and the size of the argument argp in bytes. Macros and defines used in specifying an ioctl() request are located in the file &lt;sys/ioctl.h&gt;.

## mprotect()
mprotect() changes protection for the calling process's memory page(s) containing any part of the address range in the interval [addr, addr+len-1]. addr must be aligned to a page boundary.

If the calling process tries to access memory in a manner that violates the protection, then the kernel generates a SIGSEGV signal for the process.

## prctl()
The prctl() performs operations on a process.

prctl() is called with a first argument describing what to do (with values defined in &lt;linux/prctl.h&gt;), and further arguments with a significance depending on the first one.

## read
read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

On files that support seeking, the read operation commences at the current file offset, and the file offset is incremented by the number of bytes read. If the current file offset is at or past the end of file, no bytes are read, and read() returns zero.

If count is zero, read() may detect the errors described below. In the absence of any errors, or if read() does not check for errors, a read() with a count of 0 returns zero and has no other effects.

If count is greater than SSIZE_MAX, the result is unspecified.

## write()
write() writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd.

The number of bytes written may be less than count if, for example, there is insufficient space on the underlying physical medium, or the RLIMIT_FSIZE resource limit is encountered (see setrlimit(2)), or the call was interrupted by a signal handler after having written less than count bytes. (See also pipe(7).)

For a seekable file (i.e., one to which lseek(2) may be applied, for example, a regular file) writing takes place at the current file offset, and the file offset is incremented by the number of bytes actually written. If the file was open(2)ed with O_APPEND, the file offset is first set to the end of the file before writing. The adjustment of the file offset and the write operation are performed as an atomic step.
