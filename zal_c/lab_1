#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int foo(int* p_x) {
    (*p_x)++;
    return 0;
}

int main() {
    printf("Petuhova Daria Ivanovna\n");
    //Petuhova Daria Ivanovna
    int array[3];
    array[0] = 11;
    array[1] = 21;
    array[2] = 32;

    for (int i = 0; i < 3; i++) {
        printf("%d\n", array[i]);
    }
    printf("<=====>\n");

    int* p_array = array;
    for (int i = 0; i < 3; i++) {
        printf("Value:\t %d\nAddress in memory:\t %d\n", *(p_array + i), p_array + i);
    }

    printf("<=====>\n");
    int a = 0;
    printf("Before increment\na = %d\n", a);
    foo(&a);
    printf("After increment\na = %d\n", a);

    return 0;
}