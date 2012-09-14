#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <source> <target_dir> <amount>\n", argv[0]);
    return 1;
  }

  const char *source = argv[1];

  unsigned int num;
  sscanf(argv[3], "%u", &num);
  
  unsigned int destlen = strlen(argv[2]);
  unsigned int digits = (int) log10((float) num) + 1;
  char dest[destlen + digits + 2];

  memcpy(dest, argv[2], destlen);
  if(dest[destlen - 1] != '/')
  	dest[destlen++] = '/';
  memset(&dest[destlen], 48, digits);
  dest[destlen + digits] = '\0';
 
  for(int i = 0; i < num; i++) {
    // Increment decimal number.
    int done = 0;
    char *cur = &dest[destlen + digits];
    do {
      --cur;
      *cur += 1;
      if(*cur == 58) {
        *cur = 48;
      } else {
        done = 1;
      }
    } while(!done);
      
    link(source, dest);
  }

	return 0;
}
