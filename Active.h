#ifndef PG2_DUNGEONCRAWLER_ACTIVE_H
#define PG2_DUNGEONCRAWLER_ACTIVE_H

#include "Passive.h"
#include <vector>

class Active {
public:
    Active();
    void attach(Passive*);
    void detach(Passive*);
    void active();
protected:
    std::vector<Passive*> observers;
    int findObserver(Passive*);
};


#endif //PG2_DUNGEONCRAWLER_ACTIVE_H
