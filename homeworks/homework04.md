## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.

The C library provides the abstraction of a file system that maps from file names to streams of bytes. This abstraction is built on top of storage devices that are actually organized in blocks. An example of something that is logically true about file systems but not true of their implementations is that when you write something onto a file, it seems like the bytes of that file get modified immediately. But in reality, it is the block in memory that gets modified, and it might not be copied back to the disk right away. Data written to a file is actually "buffered" which means it is stored in memory and only written to disk when there is at least one block to write.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

It  probably contains information about the open file that the system needs when the file is accessed, such as the file name and position.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Block transfers - Systems generally try to read large blocks each time they access the disk.

Prefetching - The operating system might start loading additional blocks before they are requested.

Buffering - When you write a file, the operating system stores the data in memory and only writes it to disk later. If you modify the block several times while it is in memory, the system only has to write it to disk once.

Caching - If a process has used a block recently, it is likely to use it again soon. If the operating system keeps a copy of the block in memory, it can handle future requests at memory speed.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?

It is likely that the data written to the file was "buffered" or "cached" and had not yet been written to the disk. It was probably still being stored in volatile memory so when the computer crashed, the file was gone.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

One advantage of a File Allocation Table over a UNIX node is that they scale linearly, whereas with UNIX nodes, as file sizes increase you need more and more indirection blocks. On the other hand, using a FAT can be less reliable than a UNIX inode because the table has to be referenced before accessing a block.

6) What is overhead?  What is fragmentation?

Overhead references the space taken up by data structures used by the allocator. Fragmentation is the unused space when some blocks are left unused or only partially used.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is a good idea because it is useful for many things, not just file systems. For example, it enables inter-process communication and makes it so that programmers only have to learn one API. It also makes programs more versatile, since a program intended to work with files can also work with data coming from pipes and other sources. One drawback to the abstraction is that it does not always work between different operating systems.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).
