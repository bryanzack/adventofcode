#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
  int highestSum = 0, temp = 0;
  vector<int> highestSums;
  ifstream file("input.txt");
  string line;
  while (getline(file, line)) {
    if (line != "") {
      temp += stoi(line);
    }
    else {
      if (highestSums.size() < 3) {
        highestSums.push_back(temp);
        temp = 0;
      }
      else {
        int min_pos = distance(highestSums.begin(), min_element(highestSums.begin(), highestSums.end()));
        if (temp > highestSums[min_pos]) {
          highestSums[min_pos] = temp;
        }
        temp = 0;
      }
    }
  }
  int total = 0;
  for (int sum : highestSums)
    total += sum;
  cout << "sum of top 3: " << total << endl;
  return 0;
}
