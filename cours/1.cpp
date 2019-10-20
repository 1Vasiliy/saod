#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

//      C = 2 - по году издания и автоpу, К = год издания;
//      S = 1   Meтод Вилльямса-Флойда
//      Файл    базы   данных   загpужается   в   динамическую   память с
//      фоpмиpованием индексного массива как массива указателей.

struct record {
  char author[12];
  char title[32];
  char publisher[16];
  short int year;
  short int numOfPage;
};

// void buildHeap(record &data[], record &index[], int l, int r);
//
// void heapSort(record &data[], record &index[]);

void kbhit();

int main() {

  char answ;
  FILE *fp;
  fp = fopen("testBase1.dat", "rb");
  record data[4000] = {0};

  int i = 0;
  i = fread((record *)data, sizeof(record), 4000, fp);

  for (int i = 0; i < 4000; ++i) {
    std::cout << i << ". " << data[i].author << "|" << data[i].title << "|"
              << data[i].publisher << "|" << data[i].year << "|"
              << data[i].numOfPage << "|" << std::endl;
    if (i % 20 == 0 && i != 0) {
      std::cout << "Continue?(ANY KEY / N)" << '\n';
      kbhit();
    }
  }

  record *indexArray[4000];

  for (int i = 0; i < 4000; i++) {
    indexArray[i] = &data[i];
  }

  // heapSort(data, indexArray);

  fclose(fp);
  return 0;
}

void kbhit() {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  if (ch == 'N') {
    exit(0);
  }
}

void buildHeap(record data[], record index[], int l, int r) {
  record *x = index[l];
  int i = l;
  do {
    int j = 2 * i + 1;
    if (j > r) {
      break;
    }
    if (j < r && strcmp(index[j + 1]->title, index[j]->title) <= 0) {
      ++j;
    }
    if (strcmp(x->title, index[j]->title) <= 0) {
      break;
    }
    index[i] = index[j];
    i = j;
  } while (true);
  index[i] = x;
}

void heapSort(record data[], record index[]) {
  int l = 4000 / 2 - 1;
  while (l >= 0) {
    buildHeap(data, index, l, 4000 - 1);
    --l;
  }
  int r = 4000 - 1;
  while (r >= 1) {
    record *temp = index[0];
    index[0] = index[r];
    index[r] = temp;
    --r;
    buildHeap(data, index, 0, r);
  }
  // std::reverse(index.begin(), index.end());
}
