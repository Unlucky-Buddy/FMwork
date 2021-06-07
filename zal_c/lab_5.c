#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define sizeArray 100

struct resultSearch {
    int foundElement;
    int countGo;
};
struct resultSearch linearSearch(int array[], int requiredElement) {
    int i, count = 0;
    for (i = 0; i < sizeArray; i++) {
        if (array[i] == requiredElement) { break; }
        else { count++; }
    }
    struct resultSearch result;
    result.foundElement = i + 1;
    result.countGo = count;
    return result;
}
struct resultSearch binarySearch(int array[], int requiredElement) {
    int middle = 1, left = 0, right = sizeArray, i = 0, count = 0;;
    struct resultSearch result;
    while (1 == 1) {
        middle = (left + right) / 2;
        if (array[middle] == requiredElement) {
            result.foundElement = middle + 1;
            result.countGo = count;
            return result;
        }
        else {
            if (array[middle] > requiredElement) {
                right = middle - 1;
            }
            else { left = middle + 1; }
        }
        if (left > right) {
            result.foundElement = 0;
            result.countGo = count;
            return result;
        }
        count++;
    }
}
int main()
{
    system("chcp 1251"); system("cls");
    
    int array[sizeArray];
    int* _array = &array;
    printf("Petuhova Daria Ivanovna\n");
    //Petuhova Daria Ivanovna
    for (int i = 0; i < sizeArray; i++) {
        array[i] = i + 1;
        printf("%d\t", array[i]);
        if ((i % 10 == 9) & (i != 0)) {
            printf("\n");
        }
    }
    printf("Искомое число: ");
    int requiredElement = 0;
    scanf_s("%d", &requiredElement);
    struct resultSearch found;
    found = linearSearch(_array, requiredElement);
    printf("\nМетод линейного поиска\nПозиция искомого элемента: %d, а количество итераций поиска: %d", found.foundElement, found.countGo);
    found = binarySearch(_array, requiredElement);
    printf("\nМетод бинарного поиска\nПозиция искомого элемента: %d, а количество итераций поиска: %d", found.foundElement, found.countGo);
    return 0;
}
