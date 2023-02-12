#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>

// main -> uint64_to_byte_array -> uint64_to_binary_string
// main -> print_byte_array
// main -> to_big_endian -> reverse_bytes
// main -> to_little_endian -> reverse_bytes

void uint64_to_byte_array(uint64_t value, char byteArray[8][9]);
void uint64_to_binary_string(uint64_t value, char binaryString[]);
void print_byte_array(char byteArray[8][9]);
uint64_t reverse_bytes(uint64_t value);
uint64_t to_big_endian(uint64_t littleEndian);
uint64_t to_little_endian(uint64_t bigEndian);

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

void uint64_to_binary_string(uint64_t value, char binaryString[]) {

   // 2^63
   uint64_t powerOfTwo = 1UL << 63;

   for (int i = 0; i < 64; i++) {
      char binaryPart = (value & powerOfTwo) == 0 ? '0' : '1';
      binaryString[i] = binaryPart;

      powerOfTwo /= 2UL;
   }

   binaryString[64] = '\0';
}

void uint64_to_byte_array(uint64_t value, char byteArray[8][9]) {
   char binaryString64[65];
   uint64_to_binary_string(value, binaryString64);

   for (int i = 0; i < 8; i++) {
      int startIdx = i * 8;
      int endIdx = (i + 1) * 8;

      for (int j = startIdx; j < endIdx; j++) {
         char binaryPart = binaryString64[j];
         int binaryPartIdx = 8 - (endIdx - j);
         byteArray[i][binaryPartIdx] = binaryPart;
      }
      byteArray[i][8] = '\0';
   }
}

void print_byte_array(char byteArray[8][9]) {
   for (int i = 0; i < 8; i++) {
      printf("%s ", byteArray[i]);
   }
   printf("\n");
}

uint64_t reverse_bytes(uint64_t value) {
   for (int i = 0; i < 4; i++) {
      int startIdx = i * 8;
      int endIdx = (i + 1) * 8;

      for (int j = startIdx, counter = 0; j < endIdx; j++, counter++) {
         int rhsIdx = j;
         int lhsIdx = 64 - endIdx + counter;

         uint64_t rhsShift = 1UL << rhsIdx;
         uint64_t lhsShift = 1UL << lhsIdx;

         int rhsValue = (value & rhsShift) > 0 ? 1 : 0;
         int lhsValue = (value & lhsShift) > 0 ? 1 : 0;

         if (lhsValue != rhsValue) {
           if (lhsValue == 1) {
             value = value | rhsShift;
           } else {
             value = ~value;
             value = value | rhsShift;
             value = ~value;
           }

           if (rhsValue == 1) {
             value = value | lhsShift;
           } else {
             value = ~value;
             value = value | lhsShift;
             value = ~value;
           }
         }
      }
   }
   return value;
}

uint64_t to_big_endian(uint64_t littleEndian) {
  return reverse_bytes(littleEndian);
}

uint64_t to_little_endian(uint64_t bigEndian) {
  return reverse_bytes(bigEndian);
}
