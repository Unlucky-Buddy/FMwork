#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

struct date {
  int day; // типа int
  char month[20]; // типа char
  int year; // типа int
};

int main() {

printf("Petuhova Daria Ivanovna\n");
//Petuhova Daria Ivanovna

  system("chcp 1251"); system("cls");

  struct persone { 
  char firstname[20]; 
  char lastname[20]; 
  struct date Date; 
  }Persone; 

  printf("Введите имя : "); 
  scanf("%s", Persone.firstname); 
  printf("Введите фамилию : ");
  scanf("%s", Persone.lastname);
  printf("Введите дату рождения\nЧисло: ");
  scanf("%d", &Persone.Date.day); 
  printf("Месяц: ");
  scanf("%s", Persone.Date.month);
  printf("Год: ");
  scanf("%d", &Persone.Date.year); 
  printf("\nВы ввели : %s %s,\nдата рождения %d %s %d года\n", 
      Persone.firstname, 
      Persone.lastname, 
      Persone.Date.day, 
      Persone.Date.month, 
      Persone.Date.year
  ); 
  getchar(); getchar(); 
  return 0;
}





#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
struct book {
	char title[15];
	char author[15];
	int value;
};

int main() {
	system("chcp 1251");
	system("cls");
	struct book* lib;
	int i;
	if (!(lib = (struct book*)malloc(3 * sizeof(struct book)))) {
		printf("Allocation error.");
		exit(0);
	}
	else { lib = (struct book*)malloc(3 * sizeof(struct book)); }

	for (i = 0; i < 3; i++) {
		printf("Введите название %d книги : ", i + 1);
		gets((lib + i)->title);
		printf("Введите автора %d книги : ", i + 1);
		gets((*(lib + i)).author);
		printf("Введите цену %d книги : ", i + 1);
		scanf_s("%d", &(lib + i)->value);
		getchar();
	}
	for (i = 0; i < 3; i++) {
		printf("\n %d. %s ", i + 1, (lib + i)->author);
		printf("%s %d", (lib + i)->title, (lib + i)->value);
	}
	getchar();
	return 0;
}