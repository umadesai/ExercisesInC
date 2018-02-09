## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

With 5 bits, you can specify up to 32 values, so you would need 6 bits to specify a Georgian letter.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4294967296 different characters

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

In *Think OS* "storage" refers to non-volatile, longer term storage devices like hard disk drives (HDDs) and solid state drives (SSDs), while "memory" is usually some kind of random access memory (RAM).

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB stands for “gibibyte,” which is 230 bytes, while GB stands for “gigabyte,” which is 10^9 bytes. GiB is the binary unit used for memory, and GB are decimal units used for disk drives.

5) How does the virtual memory system help isolate processes from each other?

When a program reads and writes values in memory, it generates virtual addresses. The hardware, with help from the operating system, translates to physical addresses before accessing main memory. This translation is done on a per-process basis, so even if two processes generate the same virtual address, they would map to different locations in physical memory. In general, a process cannot access data belonging to another process, because there is no virtual address it can generate that maps to physical memory allocated to another process.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

It may be that placing them at opposite ends of the address space makes sense because as the stack expands, it grows down toward smaller addresses, and as the heap expands, it grows up towards larger addresses.

7) What Python data structure would you use to represent a sparse array?

I would probably use a dictionary, with tuples of coordinates as keys.

8) What is a context switch?

A mechanism where the operating system can interrupt a running process, save its stae, and then run another process. 