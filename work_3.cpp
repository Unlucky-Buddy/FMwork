#include <iostream>

using namespace std;

const int dequeN = 10; // переменная размера дека 

struct Deque {
  int data[dequeN]; // массив данных
  int last;    // указатель на конец дека
};

// функция проверки дека на пустоту
bool dequeIsEmpty(Deque *d) {
  if (d->last == 0) { return true; } 
  else { return false; }
}

// функция добавления нового элемента в начало списка
void addInStart(Deque *d) {
  // проверка на заполненность дека
  if (d->last == dequeN) {
    cout << "\nНет мест, дек заполнен\n\n";
    return;
  }
  cout << "\nЗначение > ";
  
  // получаем новый элемент
  int valueNewItem;
  cin >> valueNewItem;

  // сдвигаем все элементы вправо
  for (int i = d->last; i > 0; i--) {
    d->data[i] = d->data[i - 1];
  }
  d->data[0] = valueNewItem; // записываем новый элемент в начало
  d->last ++; // инкрементируем индекс последнего элемента
  cout << endl << "Элемент добавлен\n\n";
}

// функция добавления нового элемента в конец списка
void addInEnd(Deque *d) { //добавление элемента в конец
  // проверка на заполненность дека
  if (d->last == dequeN) {
    cout << "\nНет мест, дек заполнен\n\n";
    return;
  }
  cout << "\nЗначение > ";
  
  // получаем новый элемент
  int valueNewItem;
  cin >> valueNewItem;

  // записываем новый элемент в конец
  d->data[d->last ++] = valueNewItem;
  cout << endl << "Элемент добавлен\n\n";
}

// функция удаления первого элемента
void deleteFromStart(Deque *d) { 
  if (dequeIsEmpty(d)) { cout << "Нельзя удалить, дек пустой\n\n"; } else {
    for (int i = 0; i < d->last; i++) { // смещаем все элементы влево
      d->data[i] = d->data[i + 1];
    }
    d->last --; // декрементируем индекс последнего элемента
    cout << endl << "Элемент удален\n\n";
  }
}

// функция удаления последнего элемента
void deleteFromEnd(Deque *d) {
  if (dequeIsEmpty(d)) { cout << "Нельзя удалить, дек пустой\n\n"; } else {
    d->last --;
    cout << endl << "Элемент удален\n\n";
  }
  
}

// функция вывода дека
void readDeque(Deque *d)
{
  if (dequeIsEmpty(d)) { cout << "Нельзя удалить, дек пустой\n\n"; } else {
    for (int i = 0; i < d->last; i++) {
      cout << endl << i << ".\t" << d->data[i];
    }
    cout << endl << endl << endl;
  }
}

int main() {
  setlocale(LC_ALL, "Rus");

  Deque deque;
  Deque *d = &deque;
  d->last = 0;

  char doNumber = 5;
  while (doNumber != '0') {
    cout << "0. Exit" << endl;
    cout << "1. Добавить в начало" << endl;
    cout << "2. Добавить в конец" << endl;
    cout << "3. Удалить с начала" << endl;
    cout << "4. Удалить с конца" << endl;
    cout << "5. Вывести дек" << endl << endl;
    
    cin >> doNumber;

    switch (doNumber)
    {
      case '0':
        break;
      
      case '1':
        addInStart(d);
        break;
      
      case '2':
        addInEnd(d);
        break;
      
      case '3':
        deleteFromStart(d);
        break;
      
      case '4':
        deleteFromEnd(d);
        break;
      
      case '5':
        readDeque(d);
        break;
      
      default:
        cout << endl << "Вы не выбрали действие\n\n";
        break;
    }
  }
}