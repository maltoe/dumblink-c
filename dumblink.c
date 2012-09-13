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
  
  const unsigned int destlen = strlen(argv[2]);
  char dest[destlen + (int) (log10((float) num)) + 2];
  memcpy(dest, argv[2], destlen);
  
  char *numdest;
  if(dest[destlen - 1] == '/')
  	numdest = &dest[destlen];
  else {
  	dest[destlen] = '/';
  	numdest = &dest[destlen + 1];
  }
  
  for(int i = 0; i < num; i++) {
  	sprintf(numdest, "%u", i);
  	link(source, dest);
  }

	return 0;
}
