#include <stdio.h>
#include <stdlib.h>

/* Uses the value of the buffer to alter the count value. Adds 1 for values
between 2 and 7, and subtracts 1 for a buffer value of 10.
*/
int card_count( int val, int count)
{
  if ((val > 2)&&(val<7)){
    count++;
  } else if (val == 10) {
    count--;
  }
  printf("Current count: %i\n", count);
  return count;
}

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/

void get_card_name(char *prompt, char *card_name)
{
  int count = 0;

  do {
    puts(prompt);
    scanf("%2s", card_name);
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
        continue;
      default:
        val = atoi(card_name);
        if ((val<1)||(val>10)){
          puts("I don't understand that value!");
          continue;
        }
      }
      count = card_count(val, count);

    } while (card_name[0]!='X');

}




int main()
{
  char card_name[3];
  get_card_name("Enter the card_name: ", card_name);
  return 0;
}
