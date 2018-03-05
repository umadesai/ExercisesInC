## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I would expect malloc and free to take constant time, while calloc and realloc probably take time proportional to the size of the allocated chunk. 

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

The system could trigger a segmentation fault or get whatever value was stored at the particular location.

b) Writing to unallocated memory.

The bad value is written and a long time passes before it is read, at which time it causes problems and is hard to debug.

c) Reading from a freed chunk.

The system might read a random, bad value.

d) Writing to a freed chunk.

When someone tries to read the information that was written to the freed chunk, they could get random, bad values.

e) Failing to free a chunk that is no longer needed.

This is called a "memory leak," and if a program runs for a long time and leaks memory, its total memory use will increase indefinitely and could cause the system to run out of physical memory.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

Chrome is using most of my memory, closely followed by Sublime Text and Compiz, a compositing window manager.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Allocating a large number of small chunks causes fragmentation and space overhead. 
Fragmentation wastes space; it also slows the program down by making memory caches less effective. Space overhead is whne boundary tags and free list pointers take up space and reduce space efficiency. Caching and binning can help malloc become quicker by sorting bins by size and helping malloc know where to search for a chunk with a particular size. Defragmentation is also a technique used by many operating systems to help mitigate these problems.

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
