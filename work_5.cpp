#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct resultSearch {
  int foundElement;
  int countGo;
};

resultSearch linearSearch(int array[], int requiredElement, int sizeArray) {
  int i, count = 0;
  for (i = 0; i < sizeArray; i++) {
    if (array[i] == requiredElement) { break; } else { count ++;}
  }
  struct resultSearch result;
  result.foundElement = i + 1;
  result.countGo = count;
  return result;
}

resultSearch binarySearch(int array[], int requiredElement, int sizeArray) {
    int middle = 1, left = 0, right = sizeArray, i = 0, count = 0;;
    struct resultSearch result;
    while (true) {
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
 	int sizeArray = 100; //размерность массива
  int *array; // создаём указатель для выделения памяти
  array = new int[sizeArray]; // выделяем память под массив

  for (int i = 0; i < sizeArray; i++) {
    array[i] = i + 1;
    printf("%d\t", array[i]);
    if ((i % 10 == 9) & (i != 0)) {
        printf("\n");
    }
  }

  printf("Искомое число: ");
  int requiredElement = 0;
  cin >> requiredElement;
  resultSearch found;
	found = linearSearch(array, requiredElement, sizeArray);
  printf("\nМетод линейного поиска\nПозиция искомого элемента: %d, а количество итераций поиска: %d", found.foundElement, found.countGo);
	found = binarySearch(array, requiredElement, sizeArray);
	printf("\nМетод бинарного поиска\nПозиция искомого элемента: %d, а количество итераций поиска: %d", found.foundElement, found.countGo);

  return 0;
}