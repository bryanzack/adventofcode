#include<iostream>
#include<fstream>
#include<map>
using namespace std;
int main()
{
  // part 1: 4
  // part 2: 14
  int distinctCount = 14
  fstream file("input.txt");
  string line;
  getline(file, line);
  for (int i = 0; i < line.length(); i++) {
    map<char,int> count;
    int sum = 0;
    for (int j = 0; j < distinctCount; j++) {
      if (isalpha(line[i+j])) {
        count[line[i+j]]++ ; 
        if (count[line[i+j]] == 1) sum++;
      }
    }
    if (sum == distinctCount) {
      return i+distinctCount;
    }
  } 
  return 0;
}
