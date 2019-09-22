#include <stdio.h>
#include "myLibrary.h"

int main () {
   int a = 4408;
   char *p = decimalToBinary(a);
   printf("%s", p);
   return 0;
}