#include <stdio.h>

void bitwise_AND();
void bitwise_OR();
void bitwise_XOR();
void bitwise_BIC();
void bitwise_NOT();
void bitwise_EXP();

// C8D6
// F76E

int main(void) {

    int num1;
    int num2;

    printf("Enter the first Hex positive number (4 bytes) without '0x': ");
    scanf("%X", &num1);

    printf("Enter the second Hex positive number (4 bytes) without '0x': ");
    scanf("%X", &num2);

    int temp1 = num1;
    int temp2 = num2;

    bitwise_AND(&num1, &num2);
    printf("%X AND %X = %X\n", temp1, temp2, num1);

    bitwise_OR(&num1, &num2);
    printf("%X OR %X = %X\n", temp1, temp2, num1);

    bitwise_XOR(&num1, &num2);
    printf("%X XOR %X = %X\n", temp1, temp2, num1);
    /*
    bitwise_BIC(&num1, &num2);
    printf("%X AND %X = %X\n", temp, num2, num1);

    bitwise_NOT(&num1, &num2);

    bitwise_EXP(&num1, &num2);

    */
    return 0;
}

void bitwise_AND(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    int operationResult = temp1 & temp2;
    *nb1 = operationResult;
}

void bitwise_OR(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    int operationResult = temp1 | temp2;
    *nb1 = operationResult;
}

void bitwise_XOR(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    int operationResult = temp1 ^ temp2;
    *nb1 = operationResult;
}

void bitwise_BIC(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    int operationResult = temp1 ^ temp2;
    *nb1 &= ~(1 << temp1);
    *nb1 &= ~(1 << temp2);
}

void bitwise_NOT(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    int inverted1 = ~temp1;
    int inverted2 = ~temp2;
    *nb1 = inverted1;
    *nb2 = inverted2;
}

void bitwise_EXP(int *nb1, int *nb2) {
    int temp1 = *nb1;
    int temp2 = *nb2;
    *nb1 = ~temp1 ^ (~temp2 | (temp1 & temp2))
}
