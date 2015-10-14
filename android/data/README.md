# Tests
| Start | End | Description |
| --- | --- | --- |
| gmail-screen0 | gmail-screen9 | Run Gmail with screen ON, wifi active, adb over wifi, sync disabled, no mail present |
| white-screen0 | white-screen9 | Run EnergyWhite screen ON, wifi active, adb over wifi |

# Common system calls
## Frequency (alphabetical order)
<table>
  <tr>
    <td></td>
    <td colspan="3">Gmail</td>
    <td colspan="3">White</td>
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
</table>
* **clock_gettime**
* **epoll_pwait**
* **futex**
* **getuid32**
* **ioctl**
* **prctl**
* **write**

## Longest (alphabetical order)
<table>
  <tr>
    <td></td>
    <td colspan="3">Gmail</td>
    <td colspan="3">White</td>
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
</table>
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
