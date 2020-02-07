#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int size = 10;
int values[10];

void sums(){
  int sum = 0;
  for(int a =0; a<sizeof(values); a++)
  {
    sum += values[a];
  }
  printf("The sum is %d\n",sum);
}

void new_array (int i, int val) {
  if (i<size) {
      values[i] = val;
  } else {
    printf("Number of integers exceeds array dimentions");
    exit(0);
  }
}

void get_vals(char *prompt, char *input_val) {
  int buffer_val = 3;
  int i=0;
  int int_val = 0;
  bool end_val = false;
  do {
    puts(prompt);
    end_val = fgets(input_val, buffer_val,stdin) == NULL;
    if (strchr(input_val, '\n') == NULL) {
      int c;
      while((c = getc(stdin)) != '\n');
      printf("Input overflow. Limit in put to %i characters.\n", buffer_val );
      continue;
    }
    int_val = atoi(input_val);
    if (!end_val){
      if (int_val == 0 && *input_val){
        printf("This input is of an incompatible type. Please enter an interger");
        continue;
      }
      new_array(i,int_val);
      i++;
    }
  } while (!end_val);
    sums();
    }

int main() {
  char input_val[5];
  get_vals("Enter an integer: ", input_val);
  return 0;
}
