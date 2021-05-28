#include <iostream>

using namespace std;

struct client {
  int idClient;
  char name1[50];
  char name2[50];
  char name3[50];
  char address[100];
  char telephone[20];
};

struct films {
  int idFilm;
  char name[50];
  char company[50];
  char maker[50];
  int year;
};

struct instance{
  int idInstance;
  films id_films;
  char mediaSource[20];
  int cost;
  bool onHands;
};

struct rentHistory {
  int idRentHistory;
  client idClient;
  instance idInstance;
  char takeDate[20];
  char backDate[20];
};


int main() {
  system("chcp 1251"); system("cls");

  rentHistory history;
  rentHistory *h = &history;

  printf("\nВведите фамилию : ");
  scanf("%s", h->idClient.name1);
  printf("\nВведите имя : ");
  scanf("%s", h->idClient.name2);
  printf("\nВведите отчество : ");
  scanf("%s", h->idClient.name3);
  printf("\nВведите адрес : ");
  scanf("%s", h->idClient.address);
  printf("\nВведите телефон : ");
  scanf("%s", h->idClient.telephone);
  h->idClient.idClient = 0;

  printf("Вы ввели: \n\t%s %s %s\n\t%s\n\t%s\n\t%d",
    h->idClient.name1,  
    h->idClient.name2,
    h->idClient.name3,
    h->idClient.address,
    h->idClient.telephone,
    h->idClient.idClient
  );




























  

	return 0;
}