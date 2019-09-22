#include <stdlib.h>

char *decimalToBinary(int decimal) {
    int arrayLen = 35;
    static char binaryRepresentation[35];
    int sing = '0';
    if (decimal < 0) {
        sing = '1';
    }
    for (int i = arrayLen - 1; i >= 0; --i) {
        if (i == 26 || i == 17 || i == 8) {
            binaryRepresentation[i] = ' ';
            --i;
        }
        if (i == 0) {
            binaryRepresentation[0] = sing;
        } else if ((decimal >= 1) || (decimal <= -1)) {
            binaryRepresentation[i] = abs(decimal % 2) + '0';
            decimal /= 2;
        } else {
            binaryRepresentation[i] = '0';
        }
    }
    return binaryRepresentation;
}

char *decimalToBinary8(int decimal) {
    int arrayLen = 7;
    static char binaryRepresentation[7];

    for (int i = arrayLen; i >= 0; --i) {
        if ((decimal >= 1) || (decimal <= -1)) {
            binaryRepresentation[i] = abs(decimal % 2) + '0';
            decimal /= 2;
        } else {
            binaryRepresentation[i] = '0';
        }
    }
    return binaryRepresentation;
}
