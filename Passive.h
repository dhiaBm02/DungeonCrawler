#ifndef PG2_DUNGEONCRAWLER_PASSIVE_H
#define PG2_DUNGEONCRAWLER_PASSIVE_H

class Active;

class Passive {
public:
    Passive();
    virtual void notify(Active* source) = 0;
private:
};


#endif //PG2_DUNGEONCRAWLER_PASSIVE_H
