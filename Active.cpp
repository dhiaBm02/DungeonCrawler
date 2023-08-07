//
// Created by dhiab on 29/11/2022.
//

#include "Active.h"

Active::Active() {

}

void Active::attach(Passive * observer) {
    if (findObserver(observer) == -1) {
        observers.push_back(observer);
    }
}

void Active::detach(Passive * observer) {
    if (int index = findObserver(observer) != -1) {
        observers.erase(observers.begin() + index);
    }
}

void Active::active() {
    for (auto observer : observers) {
        observer->notify(this);
    }
}

int Active::findObserver(Passive * observer) {
    std::size_t size = observers.size();

    if (size == 0)
        return -1;

    for (int i = 0; i < size; i++) {
        if (observers.at(i) == observer) {
            return i;
        }
    }
    return -1;
}