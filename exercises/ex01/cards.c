/*
 * Program that keeps a running count of a card game.
 * Modified code from Head First C.
 * Uma Desai
 */
#include <stdio.h>
#include <stdlib.h>

/* Prompts the user with "Enter the card_name: " and updates the given card_name variable with the user's input.
 *
 * card_name: a character array (char *) that stores the user's input.
 */
get_card(char * card_name){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/* Converts the card name into a numerical value and returns this new value.
 *
 * card_name: a character array (char *) with the card name.
 */
int get_val(char * card_name){
  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      val = -1;
      break;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)) {
        puts ("I don't understand that value!");
      }
      break;
  }
  return val;
}

/* Given a card value and current count, updates the current count value.
 *
 * val: card value (int)
 * count: current count value (int)
 */
int update_count(int val, int count){
  if ((val > 2) && (val < 7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
  printf("Current count: %i\n", count);
  return count;
}


int main()
{
  char card_name[3];
  int count = 0;
  int val = 0;
  do {
    get_card(card_name);
    val = get_val(card_name);
    count = update_count(val, count);
  } while (card_name[0]!='X');
   return 0;
}
