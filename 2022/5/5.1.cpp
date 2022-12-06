#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<deque>
#include<chrono>
using namespace std;

map<int,deque<int>> parse() {
  // clean each line + populate deques
  ifstream file("input.txt"); 
  std::map<int,deque<int>>queues; 
  string line;
  while (getline(file, line)) {
    if (!line.empty()) {
      string tmp = "", tmp1 = "";  
      for (int i = 0; i < line.length(); i++)
        if (i % 2 != 0)
          tmp += line[i];
      for (int i = 0; i < tmp.length(); i++)
        if (i % 2 == 0)
          tmp1 += tmp[i];
      for (int i = 0; i < tmp1.length(); i++) {
        if (isalpha(tmp1[i])) {
          if (queues[i].empty()) {
            deque<int> *init = new deque<int>();
            queues[i] = *init; 
            queues[i].push_back(tmp1[i]);
          }
          else {
            queues[i].push_back(tmp1[i]);
          }
        }
      }
    } else return queues;
  }
}

void display(map<int,deque<int>>queues) {
  for (int i = 0; i < queues.size(); i++) {
    cout << i << ": ";
    for (auto j : queues[i])
      cout << char(j);
    cout << endl;
  }
}

string move(map<int,deque<int>>queues) {
  ifstream file("input.txt");
  string line;
  string s;
  vector<string>words;
  while(getline(file, line)) {
    if (line[0] == 'm') {
      istringstream strm(line);
      while (strm >> s) {
        words.push_back(s);
      }
      int move = stoi(words[1]),
          from = stoi(words[3])-1,
          to = stoi(words[5])-1;
      for (int i = 0; i < move; i++) {
        queues[to].push_front(queues[from].front());
        queues[from].pop_front();
      }
      words.clear();
    }
  }
  string ans = "";
  for (int i = 0; i < queues.size(); i++) {
    ans += (char)queues[i].front();
  }
  return ans;
}

int main()
{

  auto start = chrono::high_resolution_clock::now();
  map<int,deque<int>> queues = parse();
  //display(queues);
  string ans = move(queues);
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
  cout << "top: " << ans << " (" << duration.count() << "ms)" << endl;
  cout << endl;

  return 0;
}
