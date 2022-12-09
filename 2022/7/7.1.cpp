#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class Item {
public:
  int size;
  string name;
  bool isFile;
  vector<Item*>items;
  Item *parent;

  Item(string rootName) {
    this->name = rootName;
    this->isFile = false;
    this->size = 0;
  }
  Item(Item *parent, string dirName) {
    this->parent = parent;
    this->name = dirName;
    this->isFile = false;
  }
  Item(Item *parent, string size, string name) {
    this->parent = parent;
    this->name = name;
    cout << "size: " << size << endl;
    //cout << "size(stoi): " << stoi(size) << endl;
    this->size = stoi(size);
    this->isFile = true;
  }
};

void navigateTo(Item *root, Item *&currentItem, string targetDir) {
  if (root->items.size() == 0) return;
  for (Item *item : currentItem->items) {
    if (!item->isFile) {
      if (item->name == targetDir) {
        currentItem = item;
      }
    }
  }
}

void printTree(Item *root) {
  cout << endl;
  if (root == NULL) return;
  for (Item *item : root->items) {
  if (root->items.size() == 0) return;
    if (!item->isFile) {
      printTree(item);
      (item->items.size() == 0)
        ? cout << root->name << ": " << "/" << item->name << "/" << " (EMPTY)" << endl
        : cout << root->name << ": " << "/" << item->name << "/" << item->size << endl;
    }
    else {
      cout << root->name << ": " << item->name << " (" << item->size << ") " << endl;
    }
  }
}

// the last candidate # in output is solution to part 1
int findTotalSum(Item *root) {
  if (root == NULL) return 0;
  int sum = 0;
  static int candidateSum = 0;
  for (Item *item : root->items) {
    if (!item->isFile) {
      int dirSize = findTotalSum(item);
      item->size = dirSize;
      if (dirSize <= 100000) {
        cout << "candidate: " << item->name << " (" << candidateSum << " + " << dirSize << ")";
        candidateSum += dirSize;
        cout << " = " << candidateSum << endl;
      }
      sum += dirSize;
    } 
    else {
      sum += item->size;
    }
  }
  return sum;
}

int findPart2(Item *root, int totalTreeSize) {
  int requiredSpace = 30000000;
  int unusedSpace = 70000000 - totalTreeSize;
  int minSize = requiredSpace - unusedSpace;
  static int ans = totalTreeSize;

  for (Item *item : root->items) {
    if (!item->isFile) {
      if (item->size >= minSize) {
        ans = std::min(ans, item->size);
      }
      findPart2(item, totalTreeSize);
    }
  }
  return ans;
}

int main()
{
  ifstream input("input.txt");
  string line;
    
  Item *root = new Item("/");
  Item *currentItem = root;

  while (getline(input, line)) {
    istringstream ss(line);
    string identifier, second, third;
    ss >> identifier >> second >> third;

    if (identifier == "$") {
      if (second == "cd")
        if (third == "..") {
          //cout << "move back one directory" << endl;
          currentItem = currentItem->parent;
        }
        else {
          //cout << "navigate to: " << third << endl;
          navigateTo(root, currentItem, third);
        }
      else {
        //cout << "print contents" << endl;
      }
    }
    else if (identifier == "dir") {
      //cout << "create directory: " << second << endl;
      currentItem->items.push_back(new Item(currentItem, second)); 
    }
    else {
      //cout << "create file " << second << endl;
      currentItem->items.push_back(new Item(currentItem, identifier, second));
    }
  }

  //printTree(root);
  cout << endl << endl;
  cout << "total tree size: " << findTotalSum(root) << endl;

  int totalTreeSize = findTotalSum(root);
  cout << "min file over threshhold: " << findPart2(root, totalTreeSize) << endl;


  return 0;  
}
