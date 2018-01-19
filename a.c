#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define FILE_LEN (1024*1024*5)
/*createfile()
used to create a file that has (int)length bytes
a bit has a possibility of n% to be identical to the previous bit
*/
char* createfile(int length,int n){
  int bit_now=0;
  int bit_pre=0;
  char *file;
  file = (char *)malloc(length*sizeof(char));
  char c=0;
  srand((unsigned int)time(NULL));
  int i,j;
  for (i=0; i<length; i++){
    c = 0;
    for (j=0; j<8; j++){
      bit_now = (rand()%100 < n)? bit_pre: ~bit_pre;
      c = (c | (char)(bit_now*pow(2,j)));
    }
    file[i] = c;
  }
  return file;
}
int main(){
  int n;
  char *file;
  FILE *f;
  char filename[256];
  int i;
  for (n=10; n<100 ;n+=10){
    sprintf(filename, "%d.txt", n);
    printf("creating file %s ...",filename);
    if((f = fopen(filename, "w")) == NULL){
      printf("File Error,%d\n",n);
      exit(1);
    }
    file = createfile(FILE_LEN,n);
    for (i=0; i<FILE_LEN; i++){
      fputc(file[i], f);
    }
    free(file);
    fclose(f);
    printf("done\n",filename);
  }
  return 0;
}
