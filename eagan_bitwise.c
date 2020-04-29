#include <stdio.h>

void bitwise_AND();
void bitwise_OR();
void bitwise_XOR();
void bitwise_BIC();
void bitwise_NOT();
void bitwise_EXP();
void shift_Left_Right();

// C8D6
// F76E

int main(void) {

    int num1;
    int num2;

    int shiftValue;
    int shiftAmount;
    int array[2];

    printf("Enter the first Hex positive number (4 bytes) without '0x': ");
    scanf("%X", &num1);

    printf("Enter the second Hex positive number (4 bytes) without '0x': ");
    scanf("%X", &num2);

    printf("\n");

    const int temp1 = num1;
    const int temp2 = num2;

    bitwise_AND(&num1, &num2);
    printf("%X AND %X = 0x%X\n", temp1, temp2, num1);

    num1 = temp1;
    num2 = temp2;

    bitwise_OR(&num1, &num2);
    printf("%X OR %X = 0x%X\n", temp1, temp2, num1);

    num1 = temp1;
    num2 = temp2;

    bitwise_XOR(&num1, &num2);
    printf("%X XOR %X = 0x%X\n", temp1, temp2, num1);

    num1 = temp1;
    num2 = temp2;

    bitwise_BIC(&num1, &num2);
    printf("%X BIC %X = 0x%X\n", temp1, temp2, num1);

    num1 = temp1;
    num2 = temp2;

    bitwise_NOT(&num1, &num2);
    printf("NOT %X = 0x%X\nNOT %X = 0x%X\n", temp1, num1, temp2, num2);

    num1 = temp1;
    num2 = temp2;

    bitwise_EXP(&num1, &num2);
    printf("NOT %X XOR (NOT %X OR (%X AND %X)) = 0x%X\n", temp1, temp2, temp1, temp2, num1);

    printf("\n");

    printf("Enter the positive in Hex(8 bytes) to be shifted without prefix '0x': ");
    scanf("%X", &shiftValue);

    printf("By how many positions do you want to shift the number?: ");
    scanf("%d", &shiftAmount);

    printf("\n");
    shift_Left_Right(shiftValue, shiftAmount, array);

    printf("Left shift by %d positions of %X is: %X\n", shiftAmount, shiftValue, array[0]);
    printf("Right shift by %d positions of %X is: %X\n", shiftAmount, shiftValue, array[1]);

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
    *nb1 = temp1 & ~temp2;
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
    *nb1 = ~temp1 ^ (~temp2 | (temp1 & temp2));
}

void shift_Left_Right(int value, int shift, int *arr) {
    arr[0] = value << shift;
    arr[1] = value >> shift;
}
