## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

This type behaves like a structure, so if you assign it to a variable you are making a copy of the contents. In POSIX, the behavior of the copy is undefined. You need to treat it like an object and pass it by pointer.

2) When you use a Semaphore as a mutex, what should its initial value be?

When you use a semaphore as a mutex, you usually initialize it to 1 to indicate that the mutex is unlocked; that is, one thread can pass the semaphore without blocking.

3) Can you think of another use for a Semaphore where you might use a different initial value?



4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

It means that there are 3 empty spaces in the queue, which is the number of producer threads that can execute queue_push without blocking.

5) What does it mean if `queue->space` is `-3`?



6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?



7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?



8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

Property 3: if there are threads waiting on a semaphore when a thread executes signal, then one of the waiting threads has to be woken.


