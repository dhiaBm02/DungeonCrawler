//
// Created by dhiab on 23/01/2023.
//

#include "Graph.h"

adjNode *Graph::getAdjListNode(Tile *data, int weight, adjNode *head) {
    adjNode* newNode = new adjNode {data, weight, head};
    return newNode;
}
