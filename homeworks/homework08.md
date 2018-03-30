## Homework 8

### C Exercises

[Here is a link to the ex08 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

At its most basic, the kernel’s job is to handle interrupts. An “interrupt”
is an event that stops the normal instruction cycle and causes the flow of
execution to jump to a special section of code called an “interrupt handler”.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The hardware is responsible for saving the program counter (PC), so the kernel knows where to resume. Then, usually, it is the responsibility of the interrupt handler to save the rest of the hardware state before it does anything that might modify it, and then restore the saved state before the interrupted process resumes.

3) What is the difference between an interrupt and a context switch?

Interrupt handlers can be fast because they don’t have to save the entire hardware state; they only have to save registers they are planning to use. But when an interrupt occurs, the kernel does not always resume the interrupted process. It has the option of switching to another process by using a "context switch."

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

When an operation like a disk request completes, it causes an interrupt. The interrupt handler figures out which process was waiting for the request and switches its state from blocked to ready. Then the scheduler may or may not choose to resume the unblocked process.

5) Why might a scheduler want to give higher priority to an I/O bound process?

I/O-bound processes are usually more interactive and directly connected to humans working on the machine. We care about getting the task we are doing right now done and thus it makes sense for I/O processes to be executed quickly.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical;
this is really how I make French toast.)

Instead of just fully cooking 8 slices and then 4 slices (which would take 20 minutes), start with 8 slices on the griddle and after 5 minutes, replace 4 with the uncooked 4 slices while flipping the other 4. Wait 5 more minutes before plating the 4 fully cooked slices, flipping the other 4 that are on the griddle, and adding the other 4 back onto the griddle for their last cook. This process would be 5 minutes quicker.
