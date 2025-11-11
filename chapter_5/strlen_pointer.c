#include <stdio.h>
#include <stdlib.h>


int str_len(char *s);
//int getline(char s[], int MAXLINE);

int main() {
  int c;
  int len;
  char *a = "DEADBEEF";
  len = str_len(a);

  printf("DEADBEEF is %d characters long\n", len);
}
/*The code below is one method for getting the length of a string in C.
* However there is a simpler way to achieve this using pointers 
* see strlen() function below.
 
int getline(char s[], int MAXLINE) {
  int c;
  int i = 0;
  
  for (i; i < MAXLINE && (c = getchar()) != EOF; i++) {
    s[i] = c;
    i++;
  }
  s[i] = '\0';

  return i;
}
*/

int str_len(char *s) {
  int n ;

  for (n = 0; *s != '\0'; s++) {
    n++;
  }
  return n;
}
