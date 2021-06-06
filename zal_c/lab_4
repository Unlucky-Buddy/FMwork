#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define sizeArray 100

int main()
{
    printf("Petuhova Daria Ivanovna\n");
    //Petuhova Daria Ivanovna
    
    srand(time(NULL));

    int temp = rand();
    int array[sizeArray];
    int *_array = &array;
    int countGo = 0;
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
    for (int i = 0; i < sizeArray - 1; i++) {
        for (int j = 0; j < sizeArray - i - 1; j++) {
            if (_array[j] > _array[j + 1])
            {
                temp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = temp;
                countGo++;
            }
        }
    }
    printf(" \n\n\n");
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\t", _array[i]);
        if ((i % 10 == 9) & (i != 0)) {
            printf("\n");
        }
    }
    printf("\n\nКоличество перестановок: %d", countGo);
    return 0;
}
