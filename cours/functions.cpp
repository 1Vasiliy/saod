#include "functions.hpp"

#define MAX 2
#define MIN 1

struct btreeNode {
  record *val[MAX + 1];
  int count;
  btreeNode *link[MAX + 1];
};

btreeNode *root;

/* creating new node */
btreeNode *createNode(record *val, btreeNode *child) {
  btreeNode *newNode = new btreeNode;
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

/* Places the value in appropriate position */
void addValToNode(record *val, int pos, btreeNode *node, btreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

/* split the node */
void splitNode(record *val, record **pval, int pos, btreeNode *node,
               btreeNode *child, btreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = new btreeNode;
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    addValToNode(val, pos, node, child);
  } else {
    addValToNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

/* sets the value val in the node */
int setValueInNode(record *val, record **pval, btreeNode *node,
                   btreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val->numOfPage < (node->val[1])->numOfPage) {
    pos = 0;
  } else {

    for (pos = node->count;
         (val->numOfPage < (node->val[pos])->numOfPage && pos > 1); pos--)
      ;

    // if (val->numOfPage == (node->val[pos])->numOfPage) {
    //   return 0;
    // }
  }
  if (setValueInNode(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      addValToNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

/* insert val in B-Tree */
void insertion(record *val) {
  int flag;
  record *i;
  btreeNode *child;

  flag = setValueInNode(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

/* B-Tree Traversal */
void traversal(btreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      std::cout << (myNode->val[i + 1])->numOfPage << ' ';
    }
    traversal(myNode->link[i]);
  }
}
/* B-Tree Search */
void treeSearch(btreeNode *myNode, int value) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      treeSearch(myNode->link[i], value);
      if ((myNode->val[i + 1])->numOfPage == value) {
        std::cout << (myNode->val[i + 1])->numOfPage << ' ';
      }
    }
    treeSearch(myNode->link[i], value);
  }
}

// THE END
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
  int largest = i;
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  if (l < n && comparel(arr[l], arr[largest]))
    largest = l;

  if (r < n && comparel(arr[r], arr[largest]))
    largest = r;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapSort(record *arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

void viewTree() { traversal(root); }
void treeSearch(int value) {
  // std::cout << "/* message */" << '\n';
  treeSearch(root, value);
}

// Queue

int queue::remove() {
  if (isEmpty()) {
    std::cout << "UnderFlow";
    return 0;
  }

  std::cout << "Removing " << arr[front] << '\n';

  front = (front + 1) % capacity;
  count--;
}

void queue::add(record *item) {
  if (isFull()) {
    std::cout << "OverFlow";
    exit(1);
  }

  std::cout << "Inserting " << item->author << "|" << item->title << "|"
            << item->publisher << "|" << item->year << "|" << item->numOfPage
            << "|" << std::endl;
  insertion(item);

  rear = (rear + 1) % capacity;
  arr[rear] = item;
  count++;
}

record *queue::get() {
  if (isEmpty()) {
    std::cout << "UnderFlow";
    return (NULL);
  }
  return arr[front];
}

int queue::size() { return count; }

bool queue::isEmpty() { return (size() == 0); }

bool queue::isFull() { return (size() == capacity); }

// SHENNON CODE

void shennonCoding::shennonCode(shennonCoding *alphabet, int powAlphabet) {
  double *sump = new double[powAlphabet];
  double averageLength = 0;
  int *length = new int[powAlphabet];

  int **codewords = new int *[powAlphabet];

  for (int i = 1; i <= powAlphabet; i++) {
    codewords[i] = new int[powAlphabet];
  }

  for (int i = 1; i <= powAlphabet; i++) {
    for (int j = 1; j <= powAlphabet; j++) {
      codewords[i][j] = 0;
    }
  }

  sump[0] = 0;
  for (int i = 1; i <= powAlphabet; i++) {
    sump[i] = sump[i - 1] + alphabet[i - 1].probability;
    length[i] = -log2(alphabet[i - 1].probability);
  }
  for (int i = 1; i <= powAlphabet; i++) {
    for (int j = 1; j <= length[i]; j++) {
      sump[i - 1] *= 2;
      codewords[i][j] = floor(sump[i - 1]);
      while (sump[i - 1] > 1) {
        sump[i - 1] -= 1;
      }
    }
  }

  for (int i = 1; i <= powAlphabet; i++) {
    std::cout << "| " << std::setw(4) << (int)alphabet[i - 1].symbol << " | "
              << std::setw(11) << alphabet[i - 1].probability << " | "
              << std::setw(2) << length[i] << " | ";
    for (int j = 1; j <= length[i]; j++) {
      std::cout << codewords[i][j];
    }
    std::cout << std::endl;
    averageLength += length[i] * alphabet[i - 1].probability;
  }
  std::cout << "----------------------------------------------" << '\n';
  std::cout << "| Average length = " << averageLength;
}

void shennonCoding::quickSort(shennonCoding *alphabet, int left, int right) {
  double x;
  shennonCoding temp;

  int i = left;
  int j = right;
  x = alphabet[(left + right) / 2].probability;
  do {
    while ((alphabet[i].probability > x) && (i < right))
      i++;
    while ((alphabet[j].probability < x) && (j > left))
      j--;
    if (i <= j) {
      temp = alphabet[i];
      alphabet[i] = alphabet[j];
      alphabet[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);

  if (left < j)
    quickSort(alphabet, left, j);
  if (i < right)
    quickSort(alphabet, i, right);
}

void shennonCoding::codeBase() {
  FILE *file = fopen(filename, "rb");
  shennonCoding *alphabet = new shennonCoding[256];

  int *repeats = new int[256];
  for (int i = 0; i < 256; i++) {
    repeats[i] = 0;
  }

  int powerAlphabet, count = 0;
  powerAlphabet = 0;
  unsigned char ch;

  while (!feof(file)) {
    ch = getc(file);

    if (ch != -1) {
      repeats[(int)ch]++;
    }

    if (repeats[(int)ch] == 1) {
      powerAlphabet++;
    }
  }
  fclose(file);

  for (int i = 0; i < 256; i++) {
    count += repeats[i];
  }
  for (int i = 0, j = 0; i < 256; i++) {
    if (repeats[i] != 0) {
      alphabet[j].symbol = i;
      alphabet[j].probability = (double)repeats[i] / (double)count;
      j++;
    }
  }

  double entropy = 0;
  for (int i = 0; i < 256; i++) {
    entropy += log2(alphabet[i].probability) * alphabet[i].probability;
  }
  entropy = -entropy;
  quickSort(alphabet, 0, 256);
  std::cout << std::endl;
  shennonCode(alphabet, powerAlphabet);
  std::cout << "| Entropy: " << entropy << " | " << std::endl;
  std::cout << "----------------------------------------------" << '\n';
  delete repeats;
}
