#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ENG 26
#define RUS 32

// функция шифрования текста
void readCode(int key) {

    // открываем оба файла(один на чтение, а другой на запись)
    FILE* in = fopen("C:\\Temp\\inFile.txt", "r");
    FILE* out = fopen("C:\\Temp\\outFile.txt", "w");
    char c = 'a';
    while (feof(in) == 0) {
        
        fread(&c, sizeof(char), 1, in); // читаем из файла 
        if (feof(in)) {}
        else {
            if (c >= 'A' && c <= 'Z') {
                c = c + (key % ENG);
                if (c > 'Z') { c = 'A' + (c - 'Z') - 1; }
            }
            if (c >= 'a' && c <= 'z') {
                c = c + (key % ENG);
                if (c > 'z') { c = 'a' + (c - 'z') - 1; }
            }
            if (c >= 'А' && c <= 'Я') {
                c = c + (key % RUS);
                if (c > 'Я') { c = 'А' + (c - 'Я') - 1; }
            }
            if (c >= 'а' && c <= 'я') {
                c = c + (key % RUS);
                if (c > 'я') { c = 'а' + (c - 'я') - 1; }
            }
            fwrite(&c, sizeof(char), 1, out); // записываем результат в выходной файл
        }
        //printf("%c", c);
        //c = c + key; // шифруем
        

        
    }
    // закрываем оба файла
    fclose(in);
    fclose(out);
}

// функция дешифрования 
void readText(int key) {

    // открываем оба файла(один на чтение, а другой на запись)
    FILE* in = fopen("C:\\Temp\\outFile.txt", "r");
    FILE* out = fopen("C:\\Temp\\unFile.txt", "w");
    char c = 'a';
    while (feof(in) == 0) {
        fread(&c, sizeof(char), 1, in); // читаем из файла 
        if (feof(in)) {}
        else {
            if (c >= 'A' && c <= 'Z') {
                c = c - (key % ENG);
                if (c < 'A') c = 'Z' - ('A' - c) + 1;
            }
            if (c >= 'a' && c <= 'z') {
                c = c - (key % ENG);
                if (c < 'a') c = 'z' - ('a' - c) + 1;
            }
            if (c >= 'А' && c <= 'Я') {
                c = c - (key % RUS);
                if (c < 'А') c = 'Я' - ('А' - c) + 1;
            }
            if (c >= 'а' && c <= 'я') {
                c = c - (key % RUS);
                if (c < 'а') c = 'я' - ('а' - c) + 1;
            }
            fwrite(&c, sizeof(char), 1, out); // записываем результат в выходной файл
        }        
    }
    // закрываем оба файла
    fclose(in);
    fclose(out);
}

int main() {
    setlocale(LC_ALL, "Rus");
    system("chcp 1251"); system("cls");

    printf("Petuhova Daria Ivanovna\n\n");
    //Petuhova Daria Ivanovna

    readCode(1);
    readText(1);

    printf("Расшифровка начата\nРасшифровка завершена!");
    return 0;
}