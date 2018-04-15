## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

It means that both threads (or more than two) can access the data structure at the same time, and the implementation is guaranteed to be free of race conditions when accessed by multiple threads simultaneously.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

When the index, i, gets to the end of the array, it wraps around to 0. And that’s where we run into a tricky part. If we keep adding elements to the queue, eventually next_in wraps around and catches up with next_out. But if next_in == next_out, we would incorrectly conclude that the queue was empty. If incrementing next_in lands on next_out, that means we can’t add another element without making the queue seem empty. So we stop one element before the “end” (keeping in mind that the end of the queue can be anywhere, not necessarily the end of the array).

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

If there is no mutex to protect the queue, access to the queue is not thread safe. Different threads could access array, next_in, and next_out at the same time and leave the queue in a broken, “inconsistent” state

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

If cond_wait did not unlock the mutex before blocking, no other thread would be able to access the queue, no more items could be added, and the queue would always be empty.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

The mutex has been locked and the condition is true. But it is only probably true because there might have been an interception.

6) What happens if you signal a condition variable when there are no waiting threads?

If there are no threads waiting on the condition variable, the signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

No, you do not have to lock the mutex to signal a condition variable.

8) Does the condition have to be true when you signal a condition variable?

When a condition variable is first signal, the condition is true.
