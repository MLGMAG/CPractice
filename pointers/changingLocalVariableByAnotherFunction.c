#include <stdio.h>

int changeVariableByAdress(int *address);

/*
 * Change local variable of main function by another function
 * (receiving adress of variable)
 */

int main()
{
    printf("\n");
    int variable = 10;
    printf("MAIN: variable= %d\n", variable);
    printf("MAIN: &variable= %d\n", &variable);
    int *pointer;
    printf("MAIN: initializing pointer...\n");
    printf("MAIN: assing adress of variable to pointer...\n");
    pointer = &variable;
    printf("MAIN: pointer= %d\n", pointer);
    printf("MAIN: *pointer= %d\n", *pointer);
    printf("MAIN: launching function...\n");
    changeVariableByAdress(pointer);
    printf("MAIN: end of function\n");
    printf("MAIN: variable= %d\n", variable);
    printf("\n");
    return 0;
}

int changeVariableByAdress(int *address)
{
    printf("FUNCTION: address= %d\n", address);
    printf("FUNCTION: *address= %d\n", *address);
    *address = 100;
    printf("FUNCTION: assign 100 value to *address...\n");
    printf("FUNCTION: *adress= %d\n", *address);
}
