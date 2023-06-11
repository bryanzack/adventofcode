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
    switch(values[line[2]]) {
      case 1: // need to lose                  
        switch(values[line[0]]) {
          case 1: // he has rock
            score += 3; // i need scissors
            break;
          case 2: // he has paper
            score += 1; // i need rock
            break;
          case 3: // he has scissors
            score += 2; // i need paper
        }
        break;
      case 2: // need to draw
        switch(values[line[0]]) {
          case 1: // rock
            score += 4;
            break;
          case 2: // paper
            score += 5;
            break;
          case 3: // scissors
            score += 6;
            break;
        }
        break;
      case 3: // need to win
        switch(values[line[0]]) {
          case 1: // rock
            score += 8;
            break;
          case 2: // paper
            score += 9;
            break;
          case 3: // scissors
            score += 7;
            break;
        }
        break;
    }
  }
  cout << "score: " << score << endl;
  return 0;
}
