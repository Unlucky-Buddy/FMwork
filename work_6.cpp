#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//функция "нормального" рандоманого числа
int getRandomNumber(int min, int max) {
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
  // Равномерно распределяем рандомное число в нашем диапазоне
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

struct resultSearch {
  int foundElement;
  int countGo;
};

resultSearch linearSearch(int array[], int sizeArray) {
  int i, count = 0;
  struct resultSearch result;
  result.foundElement = 0;
  result.countGo = 0;
  for (int i = 1; i < sizeArray; i++) {
      if ((array[i - 1] - array[i + 1]) % 2 == 0) {
        if (result.foundElement == 0) {
          result.foundElement = i;
        } else {
          if (array[result.foundElement] < array[i]) {
            result.foundElement = i;
          }
          result.countGo ++;
        }
      }
  }
  
  return result;
}

int main()
{
	system("chcp 1251"); system("cls");
  int min = 1; // минимальное значение случайного числа
	int max = 100; // максимальное значение случайного числа
	int sizeArray = 100; //размерность массива
  int temp = getRandomNumber(min, max);
  int *array; // создаём указатель для выделения памяти
  array = new int[sizeArray]; // выделяем память под массив
  
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
    
  cout << endl;
  resultSearch found;
	found = linearSearch(array, sizeArray);
  if (found.foundElement == 0) {
    printf("Искомых элементов нет.");
  } else {
    printf("Искомый элемент: %d", found.foundElement);
  }
	
  return 0;
}