#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <Windows.h>
//#include "Functions.h"
#define N 10

struct Date {
    int day;
    int month;
    int year;
};

struct client {
    char surname[80];
    char name[80];
	char patronymic[80];
	char address[80];
	char telephone[80];
	int asd;
};

struct films {
	char name[80];
	char company[80];
	char maker[80];
	int year;
};

struct instance {
	char mediaSource[80];
    int cost;
    int onHands;
};

int Menu() {
	int stateMenu = 0;
	printf("Выберите действие\n");
	printf("0. Выход из программы\n");
	printf("1. Ввод данных\n");
	printf("2. Вывод данных\n");
	printf("3. Изменение\n");
	printf("4. Добавление\n");
	printf("5. Сортировка\n");
	printf("\nВаш выбор: \n");
	scanf_s("%d", &stateMenu);
	return stateMenu;
}

void main() {
	system("chcp 1251"); system("cls");

	printf("Petuhova Daria Ivanovna\n");
	//Petuhova Daria Ivanovna

	int _stateMenu = 0;
	_stateMenu = Menu();

	int _actions, amountOfData = 0;

	struct Date _takeDate[N];
	struct Date _backDate[N];
	struct client _client[N];
	struct films _films[N];
	struct instance _instance[N];

	//struct rentHistory *_d = &d;
	
	while (_stateMenu != 0) {
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			printf("Введите количество данных: ");
			scanf_s("%d", &amountOfData);

			for (int i = 0; i < amountOfData; i++) {
				printf("Введите ФИО клиента\n");
				printf("Фамилия: ");
				scanf("%s", _client[i].surname);
				printf("Имя: ");
				scanf("%s", _client[i].name);
				printf("Отчество: ");
				scanf("%s", _client[i].patronymic);

				printf("Введите адрес клиента: ");
				scanf("%s", _client[i].address);
				printf("Введите телефон клиента: ");
				scanf("%s", _client[i].telephone);

				printf("\nВведите дату начала проката\n");
				printf("День: ");
				scanf("%d", &_takeDate[i].day);
				printf("Месяц: ");
				scanf("%d", &_takeDate[i].month);
				printf("Год: ");
				scanf("%d", &_takeDate[i].year);

				printf("Клиента вернул фильм?\n0. Нет\n1. Да\n");
				int chose = 0;
				scanf("%d", &chose);
				if (chose == 1) {
					printf("День: ");
					scanf("%d", &_backDate[i].day);
					printf("Месяц: ");
					scanf("%d", &_backDate[i].month);
					printf("Год: ");
					scanf("%d", &_backDate[i].year);
				}
				else {
					_backDate[i].day = 00;
					_backDate[i].month = 00;
					_backDate[i].year = 00;
				}

				printf("Название фильма: ");
				scanf("%s", _films[i].name);
				printf("Носитель: ");
				scanf("%s", _instance[i].mediaSource);
				printf("Стоимость проката: ");
				scanf("%s", _instance[i].cost);

				printf("<=============>\n");
			}


			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			for (int i = 0; i < amountOfData; i++) {
				printf("Запись %d\n", i + 1);

				printf("ФИО клиента: %s %s %s\n", _client[i].surname, _client[i].name, _client[i].patronymic);
				printf("Адрес: %s\n", _client[i].address);
				printf("Телефон: %s\n", _client[i].telephone);

				printf("Дата начала проката: %d %d %d\n", _takeDate[i].day, _takeDate[i].month, _takeDate[i].year);

				if (_backDate[i].day == 0 && _backDate[i].month == 0 && _backDate[i].year == 0) {
					printf("Фильм сейчас на руках у клиента\n");
				}
				else {
					printf("Дата начала проката: %d %d %d\n", _backDate[i].day, _backDate[i].month, _backDate[i].year);
				}

				printf("Название фильма: %s\n", _films[i].name);
				printf("Носитель: %s\n", _instance[i].mediaSource);
				printf("Стоимость проката: %s\n", _instance[i].cost);

				printf("<=============>\n");
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			printf("Выберите запись от 1 до %d: ", amountOfData);
			int i = 0;
			scanf_s("%d", &i);

			printf("Введите ФИО клиента\n");
			printf("Фамилия: ");
			scanf("%s", _client[i].surname);
			printf("Имя: ");
			scanf("%s", _client[i].name);
			printf("Отчество: ");
			scanf("%s", _client[i].patronymic);

			printf("Введите адрес клиента: ");
			scanf("%s", _client[i].address);
			printf("Введите телефон клиента: ");
			scanf("%s", _client[i].telephone);

			printf("\nВведите дату начала проката\n");
			printf("День: ");
			scanf("%d", &_takeDate[i].day);
			printf("Месяц: ");
			scanf("%d", &_takeDate[i].month);
			printf("Год: ");
			scanf("%d", &_takeDate[i].year);

			printf("Клиента вернул фильм?\n0. Нет\n1. Да\n");
			int chose = 0;
			scanf("%d", &chose);
			if (chose == 1) {
				printf("День: ");
				scanf("%d", &_backDate[i].day);
				printf("Месяц: ");
				scanf("%d", &_backDate[i].month);
				printf("Год: ");
				scanf("%d", &_backDate[i].year);
			}
			else {
				_backDate[i].day = 00;
				_backDate[i].month = 00;
				_backDate[i].year = 00;
			}

			printf("Название фильма: ");
			scanf("%s", _films[i].name);
			printf("Носитель: ");
			scanf("%s", _instance[i].mediaSource);
			printf("Стоимость проката: ");
			scanf("%s", _instance[i].cost);

			printf("<=============>\n");

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			
			int i = amountOfData + 1;
			amountOfData++;

			printf("Введите ФИО клиента\n");
			printf("Фамилия: ");
			scanf("%s", _client[i].surname);
			printf("Имя: ");
			scanf("%s", _client[i].name);
			printf("Отчество: ");
			scanf("%s", _client[i].patronymic);

			printf("Введите адрес клиента: ");
			scanf("%s", _client[i].address);
			printf("Введите телефон клиента: ");
			scanf("%s", _client[i].telephone);

			printf("\nВведите дату начала проката\n");
			printf("День: ");
			scanf("%d", &_takeDate[i].day);
			printf("Месяц: ");
			scanf("%d", &_takeDate[i].month);
			printf("Год: ");
			scanf("%d", &_takeDate[i].year);

			printf("Клиента вернул фильм?\n0. Нет\n1. Да\n");
			int chose = 0;
			scanf("%d", &chose);
			if (chose == 1) {
				printf("День: ");
				scanf("%d", &_backDate[i].day);
				printf("Месяц: ");
				scanf("%d", &_backDate[i].month);
				printf("Год: ");
				scanf("%d", &_backDate[i].year);
			}
			else {
				_backDate[i].day = 00;
				_backDate[i].month = 00;
				_backDate[i].year = 00;
			}

			printf("Название фильма: ");
			scanf("%s", _films[i].name);
			printf("Носитель: ");
			scanf("%s", _instance[i].mediaSource);
			printf("Стоимость проката: ");
			scanf("%s", _instance[i].cost);

			printf("<=============>\n");

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");


			system("pause");
			system("cls");
			Menu();
			break;

		default:
			зкштеа("Выбрана неправильное действие!\n");
			system("pause");
			system("cls");
			break;
		}
	}
}