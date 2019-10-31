#include "functions.hpp"

void buildHeap(record vector[], record *index[], int l, int r) {
  record *x = index[l];
  int i = l;
  do {
    int j = 2 * i + 1;
    if (j > r) {
      break;
    }
    if (j < r &&
        strcmp(split(index[j + 1]->author), split(index[j]->author)) <= 0) {
      ++j;
    }
    if (strcmp(split(x->author), split(index[j]->author)) <= 0) {
      break;
    }
    index[i] = index[j];
    i = j;
  } while (true);
  index[i] = x;
}

void heapSort(record vector[], record *index[]) {
  int l = SIZE / 2 - 1;
  while (l >= 0) {
    buildHeap(vector, index, l, SIZE - 1);
    --l;
  }
  int r = SIZE - 1;
  while (r >= 1) {
    record *temp = index[0];
    index[0] = index[r];
    index[r] = temp;
    --r;
    buildHeap(vector, index, 0, r);
  }
}

char *split(char *name) {
  std::string temp;

  for (int i = 0; i < strlen(name); i++) {
    if (name[i] == ' ')
      break;
    temp.push_back(name[i]);
  }

  char *result = new char[temp.size() + 1];
  std::strcpy(result, temp.c_str());

  return result;
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
  if (ch == 'N' || ch == 'n') {
    exit(0);
  }
}

void print(record data[]) {
  for (int i = 0; i < SIZE; ++i) {
    std::cout << i << ". " << data[i].author << "|" << data[i].title << "|"
              << data[i].publisher << "|" << data[i].year << "|"
              << data[i].numOfPage << "|" << std::endl;
    if (i % 20 == 0 && i != 0) {
      std::cout << "Continue?(ANY KEY / N)" << '\n';
      kbhit();
    }
  }
}

void print(record *data[]) {
  for (int i = SIZE - 1; i > 0; i--) {
    std::cout << SIZE - i << ". " << data[i]->author << "|" << data[i]->title
              << "|" << data[i]->publisher << "|" << data[i]->year << "|"
              << data[i]->numOfPage << "|" << std::endl;
    if (i % 20 == 0 && i != 0) {
      std::cout << "Continue?(ANY KEY / N)" << '\n';
      kbhit();
    }
  }
}
