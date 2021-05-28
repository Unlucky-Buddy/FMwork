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

// ������ ��������� �������
void DataEntry(rentHistory* (&d), int &n); // ���� ������ �������
void ReadingData(rentHistory* (&d), int& n, string fileName); // ������ ������ �� �����
void Print(rentHistory* d, int n); // ����� ������
void DataChange(rentHistory* (&d), int n); // ��������� ������
void DeleteData(rentHistory* (&d), int &n); // �������� ������
void Copy(rentHistory* (&d_n), rentHistory* (&d_o), int n); // ����� ������
void Copy(rentHistory& d_n, rentHistory& d_o); // ����� ������ ��������
void AddDate(rentHistory* (&d), int &n); // �������� ������
void DataSorting(rentHistory*d, int n); // ����������� ������
void SavingData(rentHistory* d, int n, string fileName); // ��������� ������