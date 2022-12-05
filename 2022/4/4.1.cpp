#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  ifstream file("input.txt");
  string line;
  int count = 0;
  while (!file.eof()) {
    getline(file, line);
    if (line.empty()) { return count; }
    replace(line.begin(), line.end(), ',', ' ');
    replace(line.begin(), line.end(), '-', ' ');
    vector<int>nums;
    for (auto i : line) {
      cout << i << " ";
      if (i != 32) { nums.push_back(i-48); }
    }
    cout << endl;

    // if the length of both ranges is the same
    if ((nums[1]-nums[0])+1 == (nums[3]-nums[2])+1) {
      cout << "same length: ";
      if (nums[0] == nums[2])
        cout << "match" << endl;
      else cout << "nomatch" << endl;
    }
    // if they are not equal
    else {
      if ((nums[1]-nums[0])+1 > (nums[3]-nums[2]+1)) {
        if (nums[2] <= nums[2]
      }
    }


    //cout << (nums[1]-nums[0])+1 << " " << (nums[3]-nums[2])+1 << endl;

    /*
    // if the lengths of the pairs are equal, check to see if starting values are the same
    // if they are, they contain each other
    if ((line[2]-line[0])+1 == ((line[6]-line[4])+1)) {
      if (line[0] == line[4]) {
        //cout << "same length: match" << endl;
        count++;
        //cout << "match" << endl;
      }
    }
    
    // if the lengths are not the same, we check to see if the last value of the vector with the smaller length
    // is less than or equal to the last value of the vector with the larger ending value
    else if ((line[2]-line[0])+1 > (line[6]-line[4])+1){
      //cout << "first list greater than second" << endl;
      (line[6] <= line[2])
        ? count++
        : count += 0;
    }
    else {
      //cout << "second hand greater than first" << endl;
      (line[2] <= line[6])
        ? count++
        : count +=0;
    }
  */
  }

  //cout << "score: " << count << endl;
  return 0;
}
