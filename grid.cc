#include <iostream>
#include "grid.h"
#include "textdisplay.h"

using namespace std;

Grid::Grid() {
      td = nullptr;
}

Grid::~Grid() {
        clearGrid();
        delete td;
}

void Grid::clearGrid() {
        theGrid.clear();
        gridSize = 0;
}

bool Grid::isWon() const {
     return won;
}

void Grid::init(int n) {
        clearGrid();
        gridSize = n;
        delete td;
        td = new TextDisplay(n);
        won = false;
        int r = 0;
        while(r < n) {
                theGrid.push_back(vector<Cell>());
                for (int c = 0; c < n; c++) {
                        theGrid[r].push_back(Cell());
                        theGrid[r][c].setCoords(r , c);
             } r++;
}
         int i = 0;
           while (i < n) {
                 for(int j = 0; j < n; j++) {
                         if (i != 0) {
                                 theGrid[i][j].attach(&theGrid[i-1][j]);
                         }
                         if (i != n - 1) {
                                 theGrid[i][j].attach(&theGrid[i+1][j]);
                         }
                         if (j != 0) {
                                 theGrid[i][j].attach(&theGrid[i][j-1]);
                         }
                         if (j != n - 1) {
                                 theGrid[i][j].attach(&theGrid[i][j+1]);
                         }
                         theGrid[i][j].attach(td);
        }
    i++; }
}


void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  bool game_over = true;
  theGrid[r][c].toggle();
  for (int x = 0; x < gridSize; x++) {
          for (int y = 0; y < gridSize; y++) {
                  if (theGrid[x][y].getState()) {
                         game_over = false;
                          break;
                  }
          }
  }
  if (game_over) {
          won = true;
}
}

ostream &operator<<(ostream &out, const Grid &g) {
         out << *g.td;
        return out;
}

void Grid::printCells() const {
    for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                 cout << theGrid[x][y].getName() << ": ";
                 cout << theGrid[x][y].getObserverNames() << endl;
            }
    }
}
