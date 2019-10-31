#include "functions.hpp"
// Sorting by AUTHOR field
void buildHeapAuthor(record data[], record *index[], int l, int r) {
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

void heapSort(record data[], record *index[], int flag) {
  int l = SIZE / 2 - 1;
  while (l >= 0) {
    if (flag == 1) {
      buildHeapAuthor(data, index, l, SIZE - 1);
    } else
      buildHeapYear(data, index, l, SIZE - 1);

    --l;
  }
  int r = SIZE - 1;
  while (r >= 1) {
    record *temp = index[0];
    index[0] = index[r];
    index[r] = temp;
    --r;
    if (flag == 1) {
      buildHeapAuthor(data, index, 0, r);
    } else
      buildHeapYear(data, index, 0, r);
  }
}

// Sorting by YEAR field
void buildHeapYear(record data[], record *index[], int l, int r) {
  record *x = index[l];
  int i = l;
  do {
    int j = 2 * i + 1;
    if (j > r) {
      break;
    }
    // if (j < r && strcmp(split(index[j + 1]->author), split(index[j]->author))
    // <= 0) {
    if (j < r && index[j + 1]->year <= index[j]->year) {
      ++j;
    }
    // if (strcmp(split(x->author), split(index[j]->author)) <= 0) {
    if (x->year <= index[j]->year) {
      break;
    }
    index[i] = index[j];
    i = j;
  } while (true);
  index[i] = x;
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

char kbhit() {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void print(record data[]) {
  char key;
  for (int i = 0; i < SIZE; ++i) {
    std::cout << i << ". " << data[i].author << "|" << data[i].title << "|"
              << data[i].publisher << "|" << data[i].year << "|"
              << data[i].numOfPage << "|" << std::endl;
    if (i % 20 == 0 && i != 0) {
      std::cout << "Continue?(ANY KEY / N)" << '\n';
      key = kbhit();
      if (key == 'n' || key == 'N') {
        return;
      }
    }
  }
}

void print(record *data[]) {
  char key;
  for (int i = SIZE - 1; i > 0; i--) {
    std::cout << SIZE - i << ". " << data[i]->author << "|" << data[i]->title
              << "|" << data[i]->publisher << "|" << data[i]->year << "|"
              << data[i]->numOfPage << "|" << std::endl;
    if (i % 20 == 0 && i != 0) {
      std::cout << "Continue?(ANY KEY / N)" << '\n';
      key = kbhit();
      if (key == 'n' || key == 'N') {
        return;
      }
    }
  }
}

std::queue<record *> binarySearch(record *arr[], int left, int right, int key) {
  std::queue<record *> q;
  unsigned int midd = 0;

  while (true) {
    midd = (left + right) / 2;

    if (key > arr[midd]->year)
      right = midd - 1;
    else if (key < arr[midd]->year)
      left = midd + 1;
    else
      break;

    if (left > right)
      return q;
  }

  while (arr[midd - 1]->year == arr[midd]->year) {
    midd--;
  }

  while (arr[midd]->year == arr[midd + 1]->year) {
    q.push(arr[midd++]);
  }
  q.push(arr[midd]);

  return q;
}
