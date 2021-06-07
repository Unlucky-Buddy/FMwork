#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define sizeArray 100


struct resultSearch {
    int foundElement;
    int countGo;
};
struct resultSearch linearSearch(int array[]) {
    int i, count = 0;
    struct resultSearch result;
    result.foundElement = 0;
    result.countGo = 0;
    for (int i = 1; i < sizeArray; i++) {
        if ((array[i - 1] - array[i + 1]) % 2 == 0) {
            if (result.foundElement == 0) {
                result.foundElement = i;
            }
            else {
                if (array[result.foundElement] < array[i]) {
                    result.foundElement = i;
                }
                result.countGo++;
            }
        }
    }
    return result;
}
int main()
{
    system("chcp 1251"); system("cls");

    srand(time(NULL));

    int temp = rand();
    int array[sizeArray];
    int* _array = &array;

    printf("Petuhova Daria Ivanovna\n\n");
    //Petuhova Daria Ivanovna

    for (int i = 0; i < sizeArray; i++) {
        _array[i] = rand();
        for (int ii = 0; ii <= i - 1; ii++) {
            if (_array[i] == _array[ii]) {
                i -= 1;
                break;
            }
        }
    }
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\t", _array[i]);
        if ((i % 10 == 9) & (i != 0)) {
            printf("\n");
        }
    }
    printf("\n");
    struct resultSearch found;
    found = linearSearch(_array);
    if (found.foundElement == 0) {
        printf("Искомых элементов нет.");
    }
    else {
        printf("Искомый элемент: %d", found.foundElement);
    }
    return 0;
}