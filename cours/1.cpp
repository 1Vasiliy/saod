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

  heapSort(data, indexDataAuthor, 1);
  heapSort(data, indexDataYear, 2);

  while (true) {
    std::cout << "Enter 1-3 to:" << '\n';
    std::cout << "1. View data" << '\n';
    std::cout << "2. View sorted data by author" << '\n';
    std::cout << "3. View sorted data by year" << '\n';
    std::cout << "4. Binary search by year of publication" << '\n';
    std::cout << "5. Exit" << '\n';

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
      print(indexDataAuthor);
      break;
    }
    case 3: {
      print(indexDataYear);
      break;
    }
    case 4: {
      int key;
      std::cout << "Enter key for search: ";
      std::cin >> key;

      std::queue<record *> q = binarySearch(indexDataYear, 0, SIZE - 1, key);

      if (q.empty()) {
        std::cout << "Not found" << '\n';
        break;
      }

      while (!q.empty()) {
        record *i = q.front();
        q.pop();
        // if (i == -1) {
        //   std::cout << "Not found" << '\n';
        //   break;
        // }
        //
        // std::cout << i - 1 << ". " << indexDataYear[i - 1]->author << "|"
        //           << indexDataYear[i - 1]->title << "|"
        //           << indexDataYear[i - 1]->publisher << "|"
        //           << indexDataYear[i - 1]->year << "|"
        //           << indexDataYear[i - 1]->numOfPage << "|" << std::endl;
        //
        std::cout << i->author << "|" << i->title << "|" << i->publisher << "|"
                  << i->year << "|" << i->numOfPage << "|" << std::endl;
        //
        // std::cout << i + 1 << ". " << indexDataYear[i + 1]->author << "|"
        //           << indexDataYear[i + 1]->title << "|"
        //           << indexDataYear[i + 1]->publisher << "|"
        //           << indexDataYear[i + 1]->year << "|"
        //           << indexDataYear[i + 1]->numOfPage << "|" << std::endl;
      }
      break;
    }
    case 5: {
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
