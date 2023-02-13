#include "endian_utils.h"
#include <byteswap.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test_utils();
void test_lib();
void assert_equals(uint64_t actual, uint64_t expected);

int testCasesCount = 10;

// big endian / little endian
uint64_t test_data[][2] = {
  {18408238150008779639UL, 8589227606311925759UL},
  {9223372036854775808UL, 128UL},
  {9223372036854775807UL, 18446744073709551487UL},
  {18446744073709551615UL, 18446744073709551615UL},
  {0UL, 0UL},
  {255UL, 18374686479671623680UL},
  {65535UL, 18446462598732840960UL},
  {4294967295UL, 18446744069414584320UL},
  {1095216660480UL, 4278190080UL},
  {281474976645120UL, 281474976645120UL}
};

int main() {
  test_lib();
  test_utils();

  return 0;
}

void test_utils() {
  for (int i = 0; i < testCasesCount; i++) {
    uint64_t bigEndianExpected = test_data[i][0];
    uint64_t littleEndianExpected = test_data[i][1];

    uint64_t littleEndianActual = to_little_endian(bigEndianExpected);
    uint64_t bigEndianActual = to_big_endian(littleEndianExpected);

    assert_equals(bigEndianActual, bigEndianExpected);
    assert_equals(littleEndianActual, littleEndianExpected);
  }

  printf("'test_utils' is passed\n");
}

void test_lib() {
  for (int i = 0; i < testCasesCount; i++) {
    uint64_t bigEndianExpected = test_data[i][0];
    uint64_t littleEndianExpected = test_data[i][1];

    uint64_t littleEndianActual = bswap_64(bigEndianExpected);
    uint64_t bigEndianActual = bswap_64(littleEndianExpected);

    assert_equals(bigEndianActual, bigEndianExpected);
    assert_equals(littleEndianActual, littleEndianExpected);
  }

  printf("'test_lib' is passed\n");
}

void assert_equals(uint64_t actual, uint64_t expected) {
  if (actual != expected) {
    printf("Assertion is failed!\nactual: '%lu'\nexpected: '%lu'\n", actual, expected);
    exit(-1);
  }
}
