#include <iostream>
#include <stdlib.h>

using namespace std;

//функция "нормального" рандоманого числа
int getRandomNumber(int min, int max) {
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
  // Равномерно распределяем рандомное число в нашем диапазоне
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
  int min = 1; // минимальное значение случайного числа
	int max = 100; // максимальное значение случайного числа
	int sizeArray = 100; //размерность массива
  int temp = getRandomNumber(min, max);
  int *array; // создаём указатель для выделения памяти
  array = new int[sizeArray]; // выделяем память под массив
  int countGo = 0;


  for (int i = 0; i < sizeArray; i++) {
    array[i] = getRandomNumber(min, max);
    for (int ii = 0; ii <= i - 1; ii++) {
      if (array[i] == array[ii]) {
        i -= 1;
        break;
      }
    }
  }
  for (int i = 0; i < sizeArray; i++) {
      printf("%d\t", array[i]);
      if ((i % 10 == 9) & (i != 0)) {
          printf("\n");
      }
  }

  // начинаем сортировать
  for (int i = 0; i < sizeArray - 1; i++) {
      for (int j = 0; j < sizeArray - i - 1; j++) {
          if (array[j] > array[j + 1]) { // мы сравниваем два соседних элемента, и если левый элемент больше правого, то мы меняем его местами
              temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
              countGo ++;
          }
      }
  }

  cout << "\n\n\n";

	// выводим отсортированный массив
  for (int i = 0; i < sizeArray; i++) {
      printf("%d\t", array[i]);
      if ((i % 10 == 9) & (i != 0)) {
          printf("\n");
      }
  }

  printf("\n\nКоличество перестановок: %d", countGo);

  delete [] array; // освобождаем память, иначе для чего мы учим с++)

  return 0;
}