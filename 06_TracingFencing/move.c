#include <stdio.h>
#include <string.h>

enum Errors {
  NO_ERROR,
  WRONG_ARGUMENTS,
  SAME_FILE,
  INPUT_OPEN_ERROR,
  OUTPUT_OPEN_ERROR,
  INPUT_READ_ERROR,
  OUTPUT_WRITE_ERROR,
  INPUT_CLOSE_ERROR,
  OUTPUT_CLOSE_ERROR
};
 

int main (int argc, char* argv[]) {
  FILE *input, *output;
  char c;
  
  if (argc < 3) {
    fprintf(stderr, "Wrong number of arguments\n");
    return WRONG_ARGUMENTS;
  }
  
  if (strcmp(argv[1], argv[2]) == 0) {
    fprintf(stderr, "Can not be the same file\n");
    return SAME_FILE;
  }
  if ((input = fopen(argv[1], "r")) == 0) {
    fprintf(stderr, "Input file not found\n");
    return INPUT_OPEN_ERROR;
  }   
  if ((output = fopen(argv[2], "w")) == 0) {
    fprintf(stderr, "Output file not found\n");
    return OUTPUT_OPEN_ERROR;
   }
    
   while(!feof(input))
   {
     c = getc(input);
     if (ferror(input)) {
       fprintf(stderr, "Can not read from input file\n");
       remove(argv[2]);
       return INPUT_READ_ERROR;
     }    
     if (!feof(input)) {
       putc(c, output);
       if (ferror(output)) {
         fprintf(stderr, "Can not write to output file\n");
         remove(argv[2]);
         return OUTPUT_WRITE_ERROR;
       }
     }                   
   }
   
  if (fclose(input) == EOF) {
     fprintf(stderr, "Can not close input file\n");
     remove(argv[2]);
     return INPUT_CLOSE_ERROR;  
   };
   
   if (fclose(output) == EOF) {
     fprintf(stderr, "Can not close output file\n");
     remove(argv[2]);
     return OUTPUT_CLOSE_ERROR;   
   };
   
   remove(argv[1]);
  
   return NO_ERROR;  
}
