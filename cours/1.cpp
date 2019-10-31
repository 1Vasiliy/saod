#include "functions.hpp"

//      C = 2 - по году издания и автоpу, К = год издания;
//      S = 1   Meтод Вилльямса-Флойда
//      Файл    базы   данных   загpужается   в   динамическую   память с
//      фоpмиpованием индексного массива как массива указателей.

void print(record data[]);
void print(record *data[]);

int main() {
  const char filename[] = "testBase1.dat";
  record data[SIZE];
  std::fstream file;

  file.open(filename, std::ios::in | std::ios::binary);

  int j = 0;
  record input;
  file.read((char *)&input, sizeof(input));
  while (!file.eof()) {
    data[j++] = input;
    file.read((char *)&input, sizeof(input));
  }

  file.close();

  record *indexData[SIZE];
  for (int i = 0; i < SIZE; i++) {
    indexData[i] = &data[i];
  }

  heapSort(data, indexData);

  std::cout << "Enter 1-3 to:" << '\n';
  std::cout << "1. View data" << '\n';
  std::cout << "2. View sorted data" << '\n';
  std::cout << "3. Binary search" << '\n';

  int n;

  std::cin >> n;

  switch (n) {
  case 1: {
    print(data);
    break;
  }
  case 2: {
    print(indexData);
    break;
  }
  default: {
    std::cout << "Incorrect input." << '\n';
    break;
  }
  }

  print(indexData);

  return 0;
}
