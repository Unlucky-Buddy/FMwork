/*
  Программа работает следующим образом:
  1. Мы создаём на диске "С" папку с именем "Temp".
    Если она существует, это не страшно, так как она приминяется как хранилище временных файлов многих программ.
  2. В папке создаём файл с именем "inFile.txt"
  3. Заполняем его и сохраняем.
  4. Переходим к программе, запускаем, после завершения возвращаемся в папку и находим два новых файла:
  "outFile.txt" и "unFile.txt"
  Первый файл содержит зашифрованное сообщение, а второй содержит расшифровку предыдущего.
  Последний файл нужен для подтверждения правильности хода шифрования и дешифрования.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
 
 // функция шифрования текста
void readCode(const char *pathInFile, const char *pathOutFile, int key) {
  
  // открываем оба файла(один на чтение, а другой на запись)
  FILE *in = fopen(pathInFile, "r");
  FILE *out = fopen(pathOutFile, "w");
  int c;
  while (!feof(in)) {
    c = 0;
    fread(&c, sizeof(int) - 2, 1, in); // читаем из файла 
    c += key; // шифруем
    fwrite(&c, sizeof(int), 1, out); // записываем результат в выходной файл
  }
  // закрываем оба файла
  fclose(in);
  fclose(out);
}

// функция дешифрования 
void readText(const char *pathInFile, const char *pathOutFile, int key) {
  
  // открываем оба файла(один на чтение, а другой на запись)
  FILE *in = fopen(pathInFile, "r");
  FILE *out = fopen(pathOutFile, "w");
  int c;
  while (!feof(in)) {
    c = 0;
    fread(&c, sizeof(int), 1, in); // читаем из файла 
    c -= key; // шифруем
    fwrite(&c, sizeof(int) - 2, 1, out); // записываем результат в выходной файл
  }
  // закрываем оба файла
  fclose(in);
  fclose(out);
}

int main() {
  system("chcp 1251"); system("cls");

  // указываем пути файлов
  char inFile[] = "C:\\Temp\\inFile.txt"; // файл с незашифрованным текстом
  char outFile[] = "C:\\Temp\\outFile.txt"; // файл с зашифрованным текстом
  char unFile[] = "C:\\Temp\\unFile.txt"; // файл с дешифрованным текстом
	
  readCode(inFile, outFile, 1); // вызываем функцию шифрования текста
  readText(outFile, unFile, 1); // вызываем функцию дешифрования
  
  // это сделано просто так, чтобы видеть, что программа завершилась
	cout << "Расшифровка начата" << endl << "Расшифровка завершена";
	return 0;
}