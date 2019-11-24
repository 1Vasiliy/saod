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

  record *indexDataAuthor[SIZE];
  record *indexDataYear[SIZE];
  for (int i = 0; i < SIZE; i++) {
    indexDataAuthor[i] = indexDataYear[i] = &data[i];
  }

  // heapSort(data, indexDataAuthor, 1);
  // heapSort(data, indexDataYear);
  heapSORT(indexDataYear, SIZE);

  int dataInt[] = {1, 4, 1, 12, 4, 2,  12, 8,  4,  12,
                   2, 8, 5, 12, 5, 11, 10, 11, 10, 12};
  // int dataInt[] = {15, 10, 14, 13, 4, 12, 6, 5, 16, 0, 17, 8, 18, 3, 19};
  int *index[15];

  for (int i = 0; i < 20; i++) {
    index[i] = &dataInt[i];
  }

  // heapSORT(dataInt, 20);

  while (true) {
    std::cout << "Enter 1-4 to:" << '\n';
    std::cout << "1. View data" << '\n';
    std::cout << "2. View sorted data by year and author" << '\n';
    std::cout << "3. Binary search by year of publication" << '\n';
    std::cout << "4. Exit" << '\n';

    int n;

    std::cin >> n;

    if (std::cin.fail()) {
      std::cerr << "You entered a string! \n";
      std::cin.clear();
      break;
    }

    switch (n) {
    case 1: {
      print(data);
      break;
    }
    case 2: {
      print(indexDataYear);
      break;
    }
    case 3: {
      int key;
      std::cout << "Enter key for search: ";
      std::cin >> key;

      queue q = binarySearch(indexDataYear, 0, SIZE - 1, key);
      // std::cout << q.peek()->author << "|"
      //           << q.peek()->title << "|"
      //           << q.peek()->publisher << "|"
      //           << q.peek()->year << "|"
      //           << q.peek()->numOfPage << "|" << std::endl;
      //
      // break;
    }
    case 4: {
      exit(0);
    }
    default: {
      std::cout << "Incorrect input." << '\n';
      break;
    }
    }
  }

  return 0;
}
