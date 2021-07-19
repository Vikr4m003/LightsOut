#include "subject.h"
#include <vector>
#include "observer.h"
#include <iostream>
#include <string>

using namespace std;

void Subject::attach (Observer *o) {
        observers.emplace_back(o);
}

string Subject::getObserverNames() const {
        vector<string> temp;
        int size = observers.size();
        int s = 0;
        while (s < size) {
                temp.emplace_back(observers[s]->getName());
                s++;
        }

        for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                        if (temp[y] > temp[x]) {
                                swap(temp[y] , temp[x]);
                        }
                }
        }
        string disp = "";
        int j = 0;
        while (j < size) {
                if (j != size - 1) {
                        disp += temp[j] + ", ";
                } else {
                        disp += temp[j];
                } j++;
        }
        return disp;
}
