#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
 
void readCode(const char *pathInFile, const char *pathOutFile, int key) {
  FILE *in = fopen(pathInFile, "r");
  FILE *out = fopen(pathOutFile, "w");
  int c;
  while (!feof(in)) {
    c = 0;
    fread(&c, sizeof(int) - 2, 1, in);
    c += key;
    fwrite(&c, sizeof(int), 1, out);
  }
  fclose(in);
  fclose(out);
}

void readText(const char *pathInFile, const char *pathOutFile, int key) {
  FILE *in = fopen(pathInFile, "r");
  FILE *out = fopen(pathOutFile, "w");
  int c;
  while (!feof(in)) {
    c = 0;
    fread(&c, sizeof(int), 1, in);
    c -= key;
    fwrite(&c, sizeof(int) - 2, 1, out);
  }
  fclose(in);
  fclose(out);
}

int main() {
  system("chcp 1251"); system("cls");
  char inFile[] = "C:\\Temp\\inFile.txt";
  char outFile[] = "C:\\Temp\\outFile.txt";
  char unFile[] = "C:\\Temp\\unFile.txt";
	readCode(inFile, outFile, 1);
  readText(outFile, unFile, 1);
  
	cout << "Расшифровка начата" << endl << "Расшифровка завершена";
	return 0;
}