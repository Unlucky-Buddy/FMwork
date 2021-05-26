#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

struct date { // создаём структуру date, в которой укажем три элемента со ледующими типами
  int day; // типа int
  char month[20]; // типа char
  int year; // типа int
};

int main() {
  system("chcp 1251"); system("cls");

  struct persone { // создаём вторую структуру persone, в которой так же будет три элемента со ледующими типами
  char firstname[20]; // тип char, с рамерностью в 20 символов
  char lastname[20]; // тип char, с рамерностью в 20 символов
  struct date Date; // типа структуры date, который мы назовём Date
  }Persone; // в конце мы можем указать имя структурной переменной 
            // в этом случае область видимости будет определяться местом описания структуры\

  printf("Введите имя : "); // выводим текст пользователю
  scanf("%s", Persone.firstname); // считываем данные, которые ввёл пользователь
  printf("Введите фамилию : ");
  scanf("%s", Persone.lastname);
  printf("Введите дату рождения\nЧисло: ");
  scanf("%d", &Persone.Date.day); // считываем данные и записываем их, обращаясь через ссылку &Persone.
  printf("Месяц: ");
  scanf("%s", Persone.Date.month); // считываем данные и записываем их напрямую
  printf("Год: ");
  scanf("%d", &Persone.Date.year); 
  printf("\nВы ввели : %s %s,\nдата рождения %d %s %d года\n", // Просто выведем полученные данные
      // ниже представлен перечень переменных, которые будут выведены
      Persone.firstname, 
      Persone.lastname, 
      Persone.Date.day, 
      Persone.Date.month, 
      Persone.Date.year
  ); // конец вывода
  getchar(); getchar(); // используем для задержки
  return 0;
}










#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 

struct book { //  создаём структуру
	char title[15]; 
	char author[15]; 
	int value; 
}; 
	
int main() { 
	system("chcp 1251"); 
	system("cls");
	struct book *lib; // объявляем указатель на объект lib типа структуры book
	int i;


	// используя malloc ВАЖНО всегда проверять возвращаемое значение на его равенство NULL, 
	// прежде чем пытаться использовать этот указатель.
	// попытка использования нулевого указателя обычно влечет крах системы.
	if (!(lib = (struct book*)malloc(3 * sizeof(struct book)))) {
		printf("Allocation error.");
		exit(0);
	} else { lib = (struct book*)malloc(3 * sizeof(struct book)); }
	
	for (i = 0; i<3; i++) { // используя цикл, заносим значения в структуру
		printf("Введите название %d книги : ", i + 1); 
		// чтобы обратиться к полям структуры необходимо использовать конструкцию lib->title или (*lib).title
		gets_s((lib + i)->title); // используем lib и инкрементируем нужное значение, чтобы обращаться к определённой ячейки памяти и занести в неё данные
		printf("Введите автора %d книги : ", i + 1); 
		gets_s((*(lib + i)).author); // первая пара скобок предназначена для перегрузок gets_s, вторая пара для разъименования указатель,
									 // а третья для правильного указания адреса в памяти
		printf("Введите цену %d книги : ", i + 1); 
		scanf_s("%d", &(lib + i)->value); 
		getchar(); 
	} 
	for (i = 0; i<3; i++) { // выводим полученные данные
		printf("\n %d. %s ", i + 1, (lib + i)->author); 
		printf("%s %d", (lib + i)->title, (lib + i)->value); 
	} 
	getchar();
	return 0; 
}