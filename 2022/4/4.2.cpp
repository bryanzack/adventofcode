#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<chrono>
#include<map>
using namespace std;
int main()
{
  auto start = chrono::high_resolution_clock::now();
  ifstream file("input.txt");
  string line;
  int count = 0;

  while (!file.eof()) {

    getline(file, line);
    if (!line.empty()) {
      replace(line.begin(), line.end(), ',', ' ');
      replace(line.begin(), line.end(), '-', ' ');  

      istringstream is(line);
      int ff, fs, sf, ss;
      string first, second;
      is >> ff >> fs >> sf >> ss;
      
      map<int,int> m;
      for (int i = ff; i <= fs; i++)
        m[i] = 1;
      for (int i = sf; i <= ss; i++){
        m[i]++;
        if (m[i] > 1) { count++; break; }
      }
    }
  }


  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
  cout << "count: " << count << " (" << duration.count() << "ms)" << endl;
  return 0;
}
