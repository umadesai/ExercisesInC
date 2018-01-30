## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

2. What is the difference between a program and a process?
A process is a software object that helps isolate each running program from the others. It is a software object that represents a running program, but is not the program itself. A process contains the text of the program, data associated with the program, the state of any pending input/output operations, and the hardware state of the program.

3. What is the primary purpose of the process abstraction?
The primary purpose of the process abstraction is to isolate each running program from the others so that programmer doesn't have to think about every possible interaction.

4. What illusion does the process abstraction create?
It creates the illusion that the complicated system of components that interact with each program are actually simple and isolated.

5. What is the kernel?
The kernel is the part of the operating system responsible for core capabilities like creating threads.

6. What is a daemon?
The daemon is another name for processes that run in the background and provide operating system services.
