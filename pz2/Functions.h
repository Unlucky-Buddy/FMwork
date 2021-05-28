#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct client {
    string surname;
    string name;
    string patronymic;
    string address;
    string telephone;
};

struct films {
    string name;
    string company;
    string maker;
    int year;
};

struct instance {
    films filmsID;
    string mediaSource;
    int cost;
    bool onHands;
};

struct rentHistory {
    client _client;
    instance _instance;
    Date _takeDate;
    Date _backDate;
};

// создаём прототипы функции
void DataEntry(rentHistory* (&d), int &n); // ввод данных вручную
void ReadingData(rentHistory* (&d), int& n, string fileName); // чтение данных из файла
void Print(rentHistory* d, int n); // вывод данных
void DataChange(rentHistory* (&d), int n); // изменение данных
void DeleteData(rentHistory* (&d), int &n); // удаление данных
void Copy(rentHistory* (&d_n), rentHistory* (&d_o), int n); // копия данных
void Copy(rentHistory& d_n, rentHistory& d_o); // копия данных элемента
void AddDate(rentHistory* (&d), int &n); // добавить данные
void DataSorting(rentHistory*d, int n); // сортировать данные
void SavingData(rentHistory* d, int n, string fileName); // сохранить данные