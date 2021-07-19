#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

using namespace std;

Cell::Cell()
{ isOn = false;
}


bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
        isOn = true;
        notifyObservers(SubscriptionType::All);
}

void Cell::toggle() {
        isOn = !(isOn);
        notifyObservers(SubscriptionType::All);
        notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Cell & whoNotified) {
        isOn = !(isOn);
        notifyObservers(SubscriptionType::All);
}

void Cell::notifyObservers(SubscriptionType t) {
        int i = 0;
        while (i < observers.size()) {
                if (observers[i]->subType() == t) {
                        observers[i]->notify(*this);
                } i++;
        }
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

string Cell::getName() const {
    string name = "(" + to_string(getRow()) + "," + to_string(getCol()) + ")";
   return name;

}
