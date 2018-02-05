/*
This program allows the user to enter integers, one per line,
until the user hits Control-D, which is the end-of-file (EOF) character.

It converts the numbers from input strings to integers and stores
the integers in an array. The program produces appropriate error messages
if the user enters something that exceeds the length of the input buffer,
can't be converted to an integer, or cannot fit in the array.

After the user enters Control-D or more than 15 numbers, the program adds up
the numbers in the array and prints the result.

Uma Desai
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define TRUE = 1;


/* Checks that the input string can be converted to an integer and is not too big.
*
* char input[]: String representation of an integral number. Stores the users input.
*/
int check_val(char input[]) {
  int val = atoi(input);
  if (val == 0 | strlen(input) > 10) {
    printf("Invalid input. Try again.\n");
  }
  else {
    return val;
  }
  return 0;
}


/* Finds the sum of all the numbers in the input_array and prints the result.
*
* int input_array[]: Integer array that stores the user's inputted integers.
*/
void find_sum(int input_array[]) {
  int sum = 0;
  int i;
  for(i = 0; i < 15; i++) {
    sum += input_array[i];
  }
  printf("Sum: %i\n.", sum);
}


/* Prompts the user for an integer input, checks for EOF, calls check_val()
* with user input, adds it to the input_array, and calls find_sum with the
* input_array.
*/
int main() {
  int input_array[15] = {0};
  char input[10];
  int j = 0;

  printf("Enter an integer: ");
  while (scanf("%s", input) != EOF) {
    if (j < 15) {
      int val = check_val(input);
      if (val != 0) {
        input_array[j] = val;
        j++;
      }
      printf("Enter another integer: \n");
    } else {
      printf("Your integer array's full. Let's add up what you've got!\n");
      break;
    }
  }
  find_sum(input_array);
  return 0;
}
