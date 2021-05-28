#include "Functions.h"

void DataEntry(rentHistory* (&d), int& n) {
	cout << "������� ���������� ������: ";
	cin >> n;

	d = new rentHistory[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ��� �������: " << endl;
		cout << "�������: ";
		cin >> d[i]._client.surname;
		cout << "���: ";
		cin >> d[i]._client.name;
		cout << "��������: ";
		cin >> d[i]._client.patronymic;

		cout << "������� ����� �������: ";
		cin >> d[i]._client.address;
		cout << "������� ������� �������: ";
		cin >> d[i]._client.telephone;


		cout << "������� ���� ������ �������: " << endl;
		cout << "����: ";
		cin >> d[i]._takeDate.day;
		cout << "�����: ";
		cin >> d[i]._takeDate.month;
		cout << "���: ";
		cin >> d[i]._takeDate.year;

		cout << endl << "������ ������ �����?" << endl << "0. ���" << endl << "1. ��" << endl;
		int chose;
		cin >> chose;
		if (chose == 1) {
			cout << "������� ���� �������� ������: " << endl;
			cout << "����: ";
			cin >> d[i]._backDate.day;
			cout << "�����: ";
			cin >> d[i]._backDate.month;
			cout << "���: ";
			cin >> d[i]._backDate.year;
		} else {
			d[i]._backDate.day = 00;
			d[i]._backDate.month = 00;
			d[i]._backDate.year = 0000;
		}

		cout << "������� �������� ������: ";
		cin >> d[i]._instance.filmsID.name;
		cout << "������� �������� ������: ";
		cin >> d[i]._instance.mediaSource;
		cout << "������� ��������� �������: ";
		cin >> d[i]._instance.cost;		

		cout << "<=============>" << endl;
	}
}

void ReadingData(rentHistory* (&d), int& n, string fileName) {
	ifstream reading(fileName);
	if (reading) {
		reading >> n;

		d = new rentHistory[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._client.surname;
			reading >> d[i]._client.name;
			reading >> d[i]._client.patronymic;

			reading >> d[i]._client.address;
			reading >> d[i]._client.telephone;

			reading >> d[i]._takeDate.day;
			reading >> d[i]._takeDate.month;
			reading >> d[i]._takeDate.year;

			reading >> d[i]._backDate.day;
			reading >> d[i]._backDate.month;
			reading >> d[i]._backDate.year;

			reading >> d[i]._instance.filmsID.name;
			reading >> d[i]._instance.mediaSource;
			reading >> d[i]._instance.cost;
		}

		cout << "������ �������!" << endl;
	} else {
		cout << "������ �������� �����!" << endl;
	}

	reading.close();
}

void Print(rentHistory* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << ":" << endl;

		cout << "��� �������: " << d[i]._client.surname << " " << d[i]._client.name << " " << d[i]._client.patronymic << endl;
			 
		cout << "�����: " << d[i]._client.address << endl;
		cout << "�������: " << d[i]._client.telephone << endl;
			 
		cout << "���� ������ �������: " << d[i]._takeDate.day << " " << d[i]._takeDate.month << " " << d[i]._takeDate.year << endl;
			 
		if (d[i]._backDate.day == 0 && d[i]._backDate.month == 0 && d[i]._backDate.year == 0) {
			cout << "����� ������ �� ����� � �������" << endl;
		} else {
			cout << "���� ��������� �������: " << d[i]._backDate.day << " " << d[i]._backDate.month << " " << d[i]._backDate.year << endl;
		}
			 
		cout << "�������� ������: " << d[i]._instance.filmsID.name << endl;
		cout << "��������: " << d[i]._instance.mediaSource << endl;
		cout << "��������� �������: " << d[i]._instance.cost << endl;

		cout << "<=============><=============><=============>" << endl;
	}
}

void DataChange(rentHistory* (&d), int n) {
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		cout << "������� ��� �������: " << endl;
		cout << "�������: ";
		cin >> d[_n]._client.surname;
		cout << "���: ";
		cin >> d[_n]._client.name;
		cout << "��������: ";
		cin >> d[_n]._client.patronymic;

		cout << "������� ����� �������: ";
		cin >> d[_n]._client.address;
		cout << "������� ������� �������: ";
		cin >> d[_n]._client.telephone;


		cout << "������� ���� ������ �������: " << endl;
		cout << "����: ";
		cin >> d[_n]._takeDate.day;
		cout << "�����: ";
		cin >> d[_n]._takeDate.month;
		cout << "���: ";
		cin >> d[_n]._takeDate.year;

		cout << endl << "������ ������ �����?" << endl << "0. ���" << endl << "1. ��" << endl;
		int chose;
		cin >> chose;
		if (chose == 1) {
			cout << "������� ���� �������� ������: " << endl;
			cout << "����: ";
			cin >> d[_n]._backDate.day;
			cout << "�����: ";
			cin >> d[_n]._backDate.month;
			cout << "���: ";
			cin >> d[_n]._backDate.year;
		}
		else {
			d[_n]._backDate.day = 00;
			d[_n]._backDate.month = 00;
			d[_n]._backDate.year = 0000;
		}

		cout << "������� �������� ������: ";
		cin >> d[_n]._instance.filmsID.name;
		cout << "������� �������� ������: ";
		cin >> d[_n]._instance.mediaSource;
		cout << "������� ��������� �������: ";
		cin >> d[_n]._instance.cost;

		system("cls");

		cout << "������ ��������!" << endl;
	} else {
		cout << "����� ����� �� �����!" << endl;
	}


}

void DeleteData(rentHistory* (&d), int &n) {
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		rentHistory* buf = new rentHistory[n];

		Copy(buf, d, n);

		--n;
		d = new rentHistory[n];

		int q = 0;

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "������ �������!" << endl;
	} else {
		cout << "����� ����� �� �����!" << endl;
	}
}

void Copy(rentHistory* (&d_n), rentHistory* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void Copy(rentHistory&d_n, rentHistory&d_o) {
		d_n._client.surname = d_o._client.surname;
		d_n._client.name = d_o._client.name;
		d_n._client.patronymic = d_o._client.patronymic;

		d_n._client.address = d_o._client.address;
		d_n._client.telephone = d_o._client.telephone;

		d_n._takeDate.day = d_o._takeDate.day;
		d_n._takeDate.month = d_o._takeDate.month;
		d_n._takeDate.year = d_o._takeDate.year;

		d_n._backDate.day = d_o._backDate.day;
		d_n._backDate.month = d_o._backDate.month;
		d_n._backDate.year = d_o._backDate.year;

		d_n._instance.filmsID.name = d_o._instance.filmsID.name;
		d_n._instance.mediaSource = d_o._instance.mediaSource;
		d_n._instance.cost = d_o._instance.cost;
}

void AddDate(rentHistory* (&d), int& n) {
	rentHistory* buf;
	buf = new rentHistory[n];

	Copy(buf, d, n);

	n++;
	d = new rentHistory[n];

	Copy(d, buf, --n);

	cout << "������� ��� �������: " << endl;
	cout << "�������: ";
	cin >> d[n]._client.surname;
	cout << "���: ";
	cin >> d[n]._client.name;
	cout << "��������: ";
	cin >> d[n]._client.patronymic;

	cout << "������� ����� �������: ";
	cin >> d[n]._client.address;
	cout << "������� ������� �������: ";
	cin >> d[n]._client.telephone;


	cout << "������� ���� ������ �������: " << endl;
	cout << "����: ";
	cin >> d[n]._takeDate.day;
	cout << "�����: ";
	cin >> d[n]._takeDate.month;
	cout << "���: ";
	cin >> d[n]._takeDate.year;

	cout << endl << "������ ������ �����?" << endl << "0. ���" << endl << "1. ��" << endl;
	int chose;
	cin >> chose;
	if (chose == 1) {
		cout << "������� ���� �������� ������: " << endl;
		cout << "����: ";
		cin >> d[n]._backDate.day;
		cout << "�����: ";
		cin >> d[n]._backDate.month;
		cout << "���: ";
		cin >> d[n]._backDate.year;
	}
	else {
		d[n]._backDate.day = 00;
		d[n]._backDate.month = 00;
		d[n]._backDate.year = 0000;
	}

	cout << "������� �������� ������: ";
	cin >> d[n]._instance.filmsID.name;
	cout << "������� �������� ������: ";
	cin >> d[n]._instance.mediaSource;
	cout << "������� ��������� �������: ";
	cin >> d[n]._instance.cost;

	system("cls");

	cout << "������ ���������!" << endl;

	delete[]buf;
}

void DataSorting(rentHistory* d, int n) {
	rentHistory buf;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._client.surname > d[j]._client.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "������ �������������!";
}

void SavingData(rentHistory* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._client.surname << endl;
			record << d[i]._client.name << endl;
			record << d[i]._client.patronymic << endl;

			record << d[i]._client.address << endl;
			record << d[i]._client.telephone << endl;

			record << d[i]._takeDate.day << endl;
			record << d[i]._takeDate.month << endl;
			record << d[i]._takeDate.year << endl;

			record << d[i]._backDate.day << endl;
			record << d[i]._backDate.month << endl;
			record << d[i]._backDate.year << endl;

			record << d[i]._instance.filmsID.name << endl;
			record << d[i]._instance.mediaSource << endl;

			if (i < n - 1) {
				record << d[i]._instance.cost << endl;
			}
			else {
				record << d[i]._instance.cost;
			}
		}
	} else {
		cout << "������ �������� �����!" << endl;
	}

	record.close();
}