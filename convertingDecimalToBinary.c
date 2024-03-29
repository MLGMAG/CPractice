#include <stdio.h>
#include <stdlib.h>

/* Functions convert decimal numbers into binary;
 *
 * I realized that functionality via division method;
 */

char *decimalToBinary32(int decimal);

char *decimalToBinary8(int decimal);

int main() {
    printf("Enter a decimal number:");
    int number;
    scanf("%d", &number);
    printf("number = %d\n", number);

    char *p;
    p = decimalToBinary32(number);
    printf("4 byte: %s\n", p);
    p = decimalToBinary8(number);
    printf("1 byte: %s\n", p);

    return 0;
}

/* Get: int;
 * Return: char* (array of char) (String);
 * Output example: (00...00 00...00 00...0 00...00);
 */
char *decimalToBinary32(int decimal) {

    // arrayLen: size of int(32) + 3 ident;
    int arrayLen = 35;
    static char binaryRepresentation[35];

    // Sing: 0=(+), 1=(-);
    int sing = '0';
    if (decimal < 0) {
        sing = '1';
    }

    /* Main functionality;
     * arrayLen-1: (35 - 1) = 34;
     * We get array of 35 - it starts at 0, ends at 34;
     * FOR realization: top -> 0;
     */
    for (int i = arrayLen - 1; i >= 0; --i) {

        /* Indentation;
         * 26 = 34-8;
         * 17 = 26-18-1(ident);
         * 8 = 17-8-1(ident);
         */
        if (i == 26 || i == 17 || i == 8) {
            binaryRepresentation[i] = ' ';
            --i;
        }


        if (i == 0) {                                                       // If it's last array element = apply sing;
            binaryRepresentation[0] = sing;
        } else if ((decimal >= 1) || (decimal <= -1)) {                      // Check for positive and negative values
            binaryRepresentation[i] = abs(decimal % 2) + '0';               // Transforming int to char: 1 -> '1'
            decimal /= 2;                                                   // Dividing main value for next step
        } else {
            binaryRepresentation[i] = '0';                                  // If value is over write zeros
        }
    }

    return binaryRepresentation;
}

/* Get: int;
 * Return: char* (array of char) (String);
 * Output: only first byte ((-255) - 255);
 */
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
