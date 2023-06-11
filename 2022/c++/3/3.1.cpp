#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<chrono>
using namespace std;
int main()
{
  auto start = chrono::high_resolution_clock::now();
  ifstream file("input.txt");
  string line;
  int score = 0;
  while (getline(file, line)) {
    string first = line.substr(0,line.length()/2),
           second = line.substr(line.length()/2, line.length());
    vector<int>vFirst, vSecond;
    for (auto f : first) { vFirst.push_back((int)f); }
    for (auto s : second) { vSecond.push_back((int)s); }
    sort(vFirst.begin(), vFirst.end());
    sort(vSecond.begin(), vSecond.end());
    stack<int, vector<int>> sFirst(vFirst);
    stack<int, vector<int>> sSecond(vSecond);
    while (sFirst.top() != sSecond.top()) {
      (sFirst.top() > sSecond.top())
        ? sFirst.pop()
        : sSecond.pop();
    }

    (isupper((char)sFirst.top()))
      ? score += sFirst.top()-38
      : score += sFirst.top()-96;
    }
  cout << "sum: " << score << endl;
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
  cout << "time elapsed: " << duration.count() << "ms" << endl;
  return 0;
}
