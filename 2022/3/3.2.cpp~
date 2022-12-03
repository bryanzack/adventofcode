#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
#include<chrono>
using namespace std;
int main()
{
  auto start = chrono::high_resolution_clock::now();
  ifstream file("input.txt");
  int count = 0;
  int sum = 0;
  map<int,vector<int>>badges;
  string line;
  while (!file.eof()) {
    if (count < 3) {
      getline(file, line);
      for (char c : line)
        badges[count].push_back((int)c);
      count++;
    }
    else {
      count--;
      while (count >= 0) {
        sort(badges[count].begin(), badges[count].end());
        count--;
      }  
      stack<int, vector<int>> sFirst(badges[0]), sSecond(badges[1]), sThird(badges[2]);
      vector<int>combined;
      while (!sFirst.empty() && !sSecond.empty()) {
        if (sFirst.top() == sSecond.top()) {
          combined.push_back(sFirst.top());
          sFirst.pop();
          sSecond.pop();
        }
        else if (sFirst.top() > sSecond.top()) {
          sFirst.pop();
        }
        else {
          sSecond.pop();
        }
      }
      sort(combined.begin(), combined.end());
      stack<int, vector<int>> sCombined(combined);
      while (sCombined.top() != sThird.top()) {
        (sCombined.top() > sThird.top())
          ? sCombined.pop()
          : sThird.pop();
      }
      count = 0;
      badges.clear();
      (isupper((char)sCombined.top()))
        ? sum += sCombined.top()-38
        : sum += sCombined.top()-96;
    }
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
  cout << "sum: " << sum << endl;
  cout << "time elapsed: " << duration.count() << "ms" << endl;

  return 0;
}
