#include "Functions.h"

int _stateMenu; // глобальная перемнная, которая указывает какое действие совершить
void Menu() {
	cout << "Выберите действие:" << endl
		<< "0. Выход из программы" << endl
		<< "1. Ввод данных" << endl
		<< "2. Вывод данных" << endl
		<< "3. Изменение" << endl
		<< "4. Удаление" << endl
		<< "5. Добавление" << endl
		<< "6. Сортировка" << endl
		<< "7. Сохранение" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main() {

	// русифицируем консоль
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	
	int _actions, amountOfData = 0;
	string fileName;

	rentHistory* d = new rentHistory[amountOfData];

	while (_stateMenu != 0) {
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			cout << "Ввод (1)вручную или (0)из файла?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1) {
				DataEntry(d, amountOfData);
			} else {
				if (_actions == 0) {
					ReadingData(d, amountOfData, "C:\\Temp\\Input.txt");
				}
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfData != 0) {
				Print(d, amountOfData);
			} else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			} else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");
			
			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			} else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");

			cout << "Введите название файла: ";
			cin >> fileName;
			fileName = "C:\\Temp\\" + fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else {
				cout << "Данные пусты!" << endl;
			}

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Неверно введён номер действия!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


}