#include <stdio.h>

int main(void) {

    int arr[10];
    int index = 0;

    int *arrEnd = arr + 10;
    for (int *i = arr; i < arrEnd; *i++) {
        *(arr + index) = index;
        printf("%5d", *(arr + index));
        index++;
    }

    printf("\n");

    index = 9;
    for (int i = arrEnd - 1; i >= arr; i--) {
        *(arr + index) = 2 * (*(arr + index)) + 4;
        printf("%5d", *(arr + index));
        index--;
    }

    printf("\n");
    return 0;
}
