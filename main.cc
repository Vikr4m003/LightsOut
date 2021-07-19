#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;
  int r, c;

  // You will need to make changes this code.

  while (true) {
   try {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
    }
    else if (cmd == "init") {
      while (cin >> r >> c) {
              if (r == -1 && c == -1) break;
              g.turnOn(r , c);
      }
      cout << g;
    }
    else if ( cmd == "neighbours" ) {
      g.printCells();
    }
    else if (cmd == "game") {
      cin >> moves;
      if (moves == 1) {
              cout << moves << " move left" << endl;
      } else {
              cout << moves << " moves left" << endl;
      }
    }
    else if (cmd == "switch") {
      int x = 0, y = 0;
      cin >> x >> y;
      g.toggle(x , y);
      moves--;
      cout << g;
      if (moves == 1) {
      cout << moves << " move left" << endl;
      } else {
      cout << moves << " moves left" << endl;
      }
      if (g.isWon() == true) {
      cout << "Won" << endl;
      }
      if (moves == 0) {
      cout << "Lost" << endl;
      }
    }
   }  catch (ios::failure &) {
           if (cin.eof()) break;
           cin.clear();
           cin.ignore();
   }
  }
}
