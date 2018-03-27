## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

The PC contains the address (in memory) of the next instruction in the program. So if you write a new value into the PC, the next instruction of the program will contain a different address and the flow of execution goes to that location.

2) What is the fundamental problem caches are meant to solve?

The "memory bottleneck" - the excess amount of time it takes to complete instructions because of the time cost of repeatedly transfering data to and from memory.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

For a hit rate of 50%, the average access time of a program would be 0.5*1 + 0.5*10 = 5.5ns.
For a hit rate of 90%, the average access time of a program would be 0.9*1 + 0.1*10 = 1.9ns.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

Arrays are implemented as a sequence of consecutive memory locations. Therefore, if the indices used in successive array operations have locality, the corresponding memory addresses will also exhibit locality. 

Hash tables are arrays, but a good hash function destroys much locality by design. Accessing the same element repeatedly will bring the appropriate hash bucket into cache. But accesses to keys that are near each other in any ordering on keys will result in memory accesses with no locality.

Source: https://www.cs.cornell.edu/courses/cs3110/2009fa/lectures/lec24.html

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

Not necessarily, because a program can be refactored to improve locality without being tailored to the size of the cache, the block size, or other hardware characteristics.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

An Intel i5-8400 has a 9MiB cache and costs $179. An Intel i5-7400 has a 6MiB cache and costs $174. That's a $5 and 3MiB cache difference which translates to ~$1.7/MiB.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Cache policies are generally more complex at the bottom of the memory hierarchy because there are fewer operations and more time to perform them, so more complex policies can be implemented. 

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

In theory, operating systems could avoid thrashing by detecting an increase in paging and blocking or killing processes until the system is responsive again.

