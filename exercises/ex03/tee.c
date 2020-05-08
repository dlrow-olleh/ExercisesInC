#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main( int argc, char *argv[]) {
  char input[10];
  puts("Enter a word: \n");
  char* word = fgets(input,sizeof(input),stdin);
  printf("%s", word);
  FILE *fp;
  char ch;
  ch = getopt(argc, argv, "a:");
  while(ch != -1){
    switch(ch) {
      case 'a':
        fprintf(stdout, "%s\n", word);
        fp = fopen(optarg,"a+");
        fwrite(word,1, sizeof(word),fp);
        fclose(fp);
        break;
      default:
      fprintf(stderr, "Error");
    }
  }
  fprintf(stdout, "%s\n", word);
  fp = fopen(argv[1], "w+");
  fwrite(word,1,sizeof(word),fp);
  fclose(fp);
  argc += optind;
  argv += optind;
}

/*Question 3
Before  I becan writing this code, I wrote down a version of what I wanted
to implement in psuedocode. This alowed me to map out the variables and proceses
I would need to implement it sucessfully. I also found it helpful to refer to
the textbook as guidance on correct ways to implement these ideas, and using
google as a resource for identifying the meaning behind various errors, and other
formating issues.

One thing that slowed me down was falling into a rabbit hole of ideas and ways
other people had implemented the tee function. It gave me lots of ideas but also
made me feel lost as they used concepts I am not yet familiar with.
*/

/*Question 4
The professional code uses error checking, something I have not considered here.
*/
