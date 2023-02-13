#ifndef ENDIAN_UTILS_H_
#define ENDIAN_UTILS_H_

#include <stdint.h>

void uint64_to_byte_array(uint64_t value, char byteArray[8][9]);
void print_byte_array(char byteArray[8][9]);
uint64_t reverse_bytes(uint64_t value);
uint64_t to_big_endian(uint64_t littleEndian);
uint64_t to_little_endian(uint64_t bigEndian);

#endif // ENDIAN_UTILS_H_
