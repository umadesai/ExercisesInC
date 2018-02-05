/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

// function that prints the address of a local variable
void print_local() {
	int var3 = 0;
	printf("Address of var3 is %p\n", &var3);
}

int main ()
{
  int var2 = 5;
  void *p = malloc(128);
  char *s = "Literal string";

  printf ("Address of main is %p\n", main);
  printf ("Address of var1 is %p\n", &var1);
  printf ("Address of var2 is %p\n", &var2);
  printf ("Address of p is %p\n", p);
  printf ("Address of s is %p\n", s);

  // Add a second call to malloc
  p = malloc(10);
  // Check whether heap on your system grows up toward larger addresses
  printf ("Address of p is %p\n", p);
  // Check whether the stack grows down
  print_local();
  void *y = malloc(1);
  void *z = malloc(32);
  printf ("Address of y is %p\n", y);
  printf ("Address of z is %p\n", z);

  return 0;
}
