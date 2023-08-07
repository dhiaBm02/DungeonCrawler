//
// Created by dhiab on 04/01/2023.
//

#ifndef PG2_DUNGEONCRAWLER_LIST_H
#define PG2_DUNGEONCRAWLER_LIST_H


#include <cstddef>
#include "Level.h"
template <typename T>
class List {

    struct Node;
    public: class iterator;

public:
    List();
    ~List();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    bool empty() const;
    std::size_t size() const;
    void remove(T data);
    iterator begin();
    iterator end();

    void print();

private:
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };
    Node* start = nullptr;
    int m_size = 0;

public: class iterator {
public:
    iterator() = default;
    explicit iterator(Node* current);
    iterator& operator++();
    iterator& operator--();
    T& operator*();
    bool operator==(const iterator& rhs);
    bool operator!=(const iterator& rhs);
private:
    Node* current;

};

};


#endif //PG2_DUNGEONCRAWLER_LIST_H
