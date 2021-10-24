#include <stdio.h>
#include <stdlib.h>
  
int main (int argc, char *argv[]) {

  int i, n, m, s;
  
  m = 0;
  s = 1;
  
  if (argc == 1) {
    printf("help\n" );
  }  
  if (argc == 2) {
    n = atoi(argv[1]);
  }  
  if (argc == 3) {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
  }
  if (argc == 4) {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    s = atoi(argv[3]);
  }
  
  if (s != 0) {
    for (i = m; i < n; i+=s) {
      printf("%d\n", i);
    }
  }
  
  return 0;
}
