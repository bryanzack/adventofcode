// win:      6pts
// draw:     3pts
// lose:     0pts
//
// (C,Z)scissors: 3pts
// (B,Y)paper   : 2pts
// (A,X)rock    : 1pt

#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;
int main()
{
  ifstream file("input.txt");
  string line;
  map<char, int> values;
  values['C'] = 3;
  values['Z'] = 3;
  values['B'] = 2;
  values['Y'] = 2;
  values['X'] = 1;
  values['A'] = 1;

  int score = 0;
  while (getline(file, line)) {
    //cout << values[line[0]] << " " << values[line[2]] << endl;
    cout << line[0] << " " << line[2] << endl;
    if (values[line[0]] == values[line[2]])
      score += values[line[2]] + 3;
    else {
      switch(values[line[2]]) {
        case 1: // rock
          (values[line[0]] == 3)
            ? score += values[line[2]] + 6
            : score += values[line[2]];
          break;
        case 2: // paper
          (values[line[0]] == 1)
            ? score += values[line[2]] + 6
            : score += values[line[2]];
          break;
        case 3: // scissors
          (values[line[0]] == 2)
            ? score += values[line[2]] + 6
            : score += values[line[2]];
          break;
      }
    }
  }
  cout << "score: " << score << endl;
  return 0;
}


// win:      6pts
// draw:     3pts
// lose:     0pts
//
// (C,Z)scissors: 3pts
// (B,Y)paper   : 2pts
// (A,X)rock    : 1pt
