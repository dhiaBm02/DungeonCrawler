//
// Created by dhiab on 04/01/2023.
//

#include "List.h"
#include "iterator"
#include <iostream>


template <typename T>
List<T>::List() {

}


template <typename T>
List<T>::~List() {
    while (start != nullptr)
        pop_back();
}


template <typename T>
void List<T>::push_back(T data) {
    if (m_size == 0) {
        start = new Node{data, nullptr, nullptr};
        m_size++;
        return;
    }
    Node* current = start;
    while (current->next != nullptr)
        current = current->next;
    current->next = new Node {data, nullptr, current};
    m_size++;

}

template <typename T>
void List<T>::push_front(T data) {
    Node* tmp = new Node {data, start, nullptr};
    start = tmp;
    m_size++;
}

template <typename T>
void List<T>::pop_back() {
    try {
        if (empty())
            throw "the list is already empty!";
        // list has single element
        if (start->next == nullptr)
        {
            delete start;
            start = nullptr;
            m_size--;
            return;
        }
        // if list has 2 or more elements, look for the second last element
        Node* current = start;
        while (current->next != nullptr)
            current = current->next;
        current = current->previous;
        current->next = nullptr;
        m_size--;
    }
    catch (const char* message) {
        std::cout << message << std::endl;
    }
}

template <typename T>
void List<T>::pop_front() {
    try {
        if (empty())
            throw "the list is already empty!";
        start = start->next;
        delete start->previous;
        start->previous = nullptr;
        m_size--;
    }
    catch (const char* message) {
        std::cout << message << std::endl;
    }
}

template <typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

template <typename T>
std::size_t List<T>::size() const {
    return m_size;
}

template <typename T>
void List<T>::remove(T data) {
    Node* current = start;
    while (current != nullptr) {
        if (current->data == data) {
            if (current == start) {
                pop_front();
                current = this->start;
                continue;
            }
            if (current->next == nullptr) {
                pop_back();
                return;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
            current = current->next;
            m_size--;
            continue;
        }
        current = current->next;
    }
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    if (!empty())
        return iterator(start);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    Node* current = start;
    while (current->next != nullptr)
        current = current->next;
    return iterator(current->next);
}

template<typename T>
void List<T>::print() {
    for (auto it = iterator(start); it != end() ; it.operator++()) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
List<T>::iterator::iterator(Node *current) : current(current) {

}

template <typename T>
typename List<T>::iterator &List<T>::iterator::operator++() {
    if (current != nullptr)
        current = current->next;
    return *this;
}

template <typename T>
typename List<T>::iterator &List<T>::iterator::operator--() {
    try {
        if (current == nullptr or current->previous == nullptr)
            throw "you cant go back anymore!";
        current = current->previous;
        return *this;
    }
    catch (const char* message) {
        std::cout << message << std::endl;
    }
}

template <typename T>
T& List<T>::iterator::operator*() {
    try {
        if (current == nullptr)
            throw "the iterator is not pointing to anything!";
        return current->data;
    }
    catch (const char* message) {
        std::cout << message << std::endl;
    }
}

template <typename T>
bool List<T>::iterator::operator==(const List::iterator & rhs) {
    return current == rhs.current;
}

template <typename T>
bool List<T>::iterator::operator!=(const List::iterator & rhs) {
    return !(*this == rhs);
}

template class List<int>;
template class List<int*>;
template class List<Level*>;

