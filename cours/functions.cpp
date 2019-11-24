#include "functions.hpp"

void heapSort(record data[], record *index[]) {
  int l = SIZE / 2 - 1;
  while (l >= 0) {
    buildHeap(data, index, l, SIZE - 1);
    --l;
  }
  int r = SIZE - 1;
  while (r >= 1) {
    record *temp = index[0];
    index[0] = index[r];
    index[r] = temp;
    --r;
    buildHeap(data, index, 0, r);
  }
}

// Sorting by YEAR field
void buildHeap(record data[], record *index[], int l, int r) {
  record *x = index[l];
  int i = l;
  do {
    int j = 2 * i + 1;
    if (j > r) {
      break;
    }
    // if (j < r && index[j + 1]->year <= index[j]->year) {
    if (j < r && comparel(index[j], index[j + 1])) {
      ++j;
    }
    if (comparel(index[j], x)) {
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

queue binarySearch(record *arr[], int left, int right, int key) {
  queue q;
  unsigned int midd = 0;

  while (true) {
    midd = (left + right) / 2;

    if (key < arr[midd]->year)
      right = midd - 1;
    else if (key > arr[midd]->year)
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
    q.add(arr[midd++]);
  }
  q.add(arr[midd]);

  return q;
}

// TESTING
//

/*
void heapSORT(record data[], record *index[]) {
  record *temp;
  int r = SIZE - 1;
  int i = 0;
  for (int i = 1; i < SIZE; i++) {
    buildHeap(index, i);
  }

  while (r != 1) {
    i = 0;
    temp = index[0];
    index[0] = index[r];
    index[r] = temp;
    r--;

    while (true) {
      if ((i + 1) * 2 <= r) {
        if (index[(i + 1) * 2 - 1]->year < index[(i + 1) * 2]->year) {
          temp = index[(i + 1) * 2];
          index[(i + 1) * 2] = index[i];
          index[i] = temp;

          i = (i + 1) * 2;
        } else {
          temp = index[(i + 1) * 2 - 1];
          index[(i + 1) * 2 - 1] = index[i];
          index[i] = temp;

          i = (i + 1) * 2 - 1;
        }
      } else if ((i + 1) * 2 - 1 <= r &&
                 index[(i + 1) * 2 - 1]->year < index[i]->year) {
        temp = index[(i + 1) * 2 - 1];
        index[(i + 1) * 2 - 1] = index[i];
        index[i] = temp;

        break;
      } else {
        break;
      }
    }
  }
}

void buildHeap(record *index[], int r) {
  record *temp;
  int i = r;
  int x;

  while (i != 0) {
    x = int((i + 1) / 2) - 1;

    if (index[i]->year > index[x]->year) {
      temp = index[x];
      index[x] = index[i];
      index[i] = temp;
    }

    i = x;
  }
}
*/

bool comparel(record *first, record *second) {

  if (first->year > second->year) {
    return true;
  } else if (first->year == second->year &&
             strcmp(split(first->author), split(second->author)) <= 0) {
    return true;
  }

  return false;
}


void heapify(record *arr[], int n, int i) {
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  if (l < n && comparel(arr[l], arr[largest]))
    largest = l;

  if (r < n && comparel(arr[r], arr[largest]))
    largest = r;

  // If largest is not root
  if (largest != i) {
    std::swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapSORT(record *arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}



//Queue
//
// queue::queue(int size)
// {
// 	capacity = size;
// 	front = 0;
// 	rear = -1;
// 	count = 0;
// }

void queue::remove()
{
	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

void queue::add(record* item)
{
	if (isFull())
	{
		std::cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

  std::cout << "Inserting " << item->author << "|"
            << item->title << "|"
            << item->publisher << "|"
            << item->year << "|"
            << item->numOfPage << "|" << std::endl;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

record* queue::peek()
{
	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

int queue::size()
{
	return count;
}

bool queue::isEmpty()
{
	return (size() == 0);
}

bool queue::isFull()
{
	return (size() == capacity);
}
