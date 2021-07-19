#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize {n} {
     for(int j = 0; j < n; j++) {
             theDisplay.emplace_back(vector<char>());
      for (int i = 0; i < n; i++) {
              theDisplay[j].emplace_back('.');
       }
     }
}

void TextDisplay::notify(Cell &whoNotified) {
        int r = whoNotified.getRow();
        int c = whoNotified.getCol();
        if (theDisplay[r][c] == '.') {
                theDisplay[r][c] = 'X';
        } else {
                theDisplay[r][c] = '.';
        }
}

TextDisplay::~TextDisplay() {
  theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

std::string TextDisplay::getName() const {
        return "TD";
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
        int i = 0;
        while(i < td.gridSize) {
                for(int j = 0; j < td.gridSize; j++) {
                 out << td.theDisplay[i][j];
                }
                i++;
                out << endl;
        }
        return out;
}
