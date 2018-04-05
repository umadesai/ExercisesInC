## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?
So that threads can call functions without interfering with each other.

2) What does the gcc flag `-lpthread` do?
It links with the Pthread library.

3) What does the argument of `pthread_exit` do?
pthread_exit passes a value to the thread that joins with the current thread.

4) Normally the same thread that created a thread also waits to join it. What happens if another thread tries to join a thread it did not create? Any thread can join any other thread, but in the most common pattern the parent thread creates and joins all child threads. 


5) What goes wrong if several threads try to increment a shared integer at the same time?
Each time you run the program, threads might be interrupted at different points, or the scheduler might choose different threads to run, so the sequence of events, and the results, will be different.

6) What does it mean to "lock a mutex"?
Before any thread can access counter, it has to “lock” the mutex, which has the effect of barring all other threads.

