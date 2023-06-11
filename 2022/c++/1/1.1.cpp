#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
  int highestsum = 0;
  int temp = 0;
  ifstream file("input.txt");
  string mystring, myline;
  if (file.is_open()) { 
    while (file) {
      getline(file, myline);
      if (myline == "") {
        if (temp > highestsum) {
          highestsum = temp;
          temp = 0;
        } else {
          temp = 0;
        }
      } else {
        temp += stoi(myline);
      }
    }
    cout << highestsum << endl;
  }

  return 0;
}
