## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/umadesai/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages commonly support dynamic types, but compiled languages are usually limited to static types.

2) Name two advantages of static typing over dynamic typing.

With static typing, the compiler checks for type errors before the program starts executing, so errors can be found more quickly and in parts of the program that have never run. Declaring types at compile time also saves space because variable names exist at compile-time but not at run time. At run time, the value of each variable is stored at its address, but the names of the variables are not stored at all.

3) Give an example of a static semantic error.

A function that is called with the wrong type or number of arguments.

4) What are two reasons you might want to turn off code optimization?

If you want to reduce compilation time, write new code, or have an easier time debugging. 

5) When you run `gcc` with `-S`, why might the results look different on different computers?

<<<<<<< HEAD
It is usually configured to generate code for the machine you are running on, so if you are running on different architectures, you might see different code.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?
=======
6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?
>>>>>>> cf2e4c9fdbd2ffad984a965c1d06a67959969c91

The spelling error could be recognized as a simple syntax error by the compiler or something different, like the linker thinking a misspelled function is a function being used that's not defined in any of the standard libraries.

7) What is a segmentation fault?

The error you get when you try to read or write an incorrect location in memory.
