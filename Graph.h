//
// Created by dhiab on 23/01/2023.
//

#ifndef PG2_DUNGEONCRAWLER_GRAPH_H
#define PG2_DUNGEONCRAWLER_GRAPH_H

#include <vector>
#include <map>
#include "Tile.h"

struct adjNode {
    Tile* data;
    int cost;
    adjNode* next;
};

struct Edge {
    Tile* from;
    Tile* to;
    int weight;
};

class Graph {
public:

private:
    adjNode* getAdjListNode(Tile* data, int weight, adjNode* head);
    std::map<std::pair<int, int>, adjNode*> adjNodes;
    int N;

};


#endif //PG2_DUNGEONCRAWLER_GRAPH_H
