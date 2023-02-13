#include <stdio.h>
#include <stdint.h>
#include "endian_utils.h"

int main() {
   char byteArray[8][9];

   uint64_t number64 = 18408238150008779639UL;

   printf("Initial: %lu\n", number64);
   uint64_to_byte_array(number64, byteArray);
   print_byte_array(byteArray);
   printf("\n");

   uint64_t bigEndian = to_big_endian(number64);

   printf("Big endian: %lu\n", bigEndian);
   uint64_to_byte_array(bigEndian, byteArray);
   print_byte_array(byteArray);
   printf("\n");

   uint64_t littleEndian = to_little_endian(bigEndian);

   printf("Little endian: %lu\n", littleEndian);
   uint64_to_byte_array(littleEndian, byteArray);
   print_byte_array(byteArray);

   return 0;
}
