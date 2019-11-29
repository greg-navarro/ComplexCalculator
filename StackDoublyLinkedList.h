//
// Created by Gregory Litman-Navarro on 11/28/19.
//

#ifndef ASSIGNMENT3_STACKDOUBLYLINKEDLIST_H
#define ASSIGNMENT3_STACKDOUBLYLINKEDLIST_H

#include <string>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Complex.h"

template class DoublyLinkedList<Complex>; // fixme can this be removed?

template <class T>
class StackDoublyLinkedList : public DoublyLinkedList<T>
{
public:
    StackDoublyLinkedList();
    void displayStack() const; //Display a stack
    T getTop() const; //return element at the top of a stack
};

/**
 * Default constructor for StackDoublyLinkedList objects.
 * @tparam T the data type that the stack's internal nodes will encapsulate
 */
template<class T>
StackDoublyLinkedList<T>::StackDoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

/**
 * Display stack.
 * @tparam T datatype of elements in stack
 */
template<class T>
void StackDoublyLinkedList<T>::displayStack() const {
    Node<T>* currentNode = this->tail;
    std::string output = ""; // fixme: are we printing???
//    int index = this->size;
    while (currentNode != nullptr)
    {
        std::cout << " " << currentNode->data << "\n";
        currentNode = currentNode->prev;
//        index++;
    }

    if (this->head == nullptr)
    {
        std::cout << "EMPTY\n";
    }
}

/**
 * Return the element located at the top of stack.
 * @tparam T data type of element
 * @return top of stack
 */
template<class T>
T StackDoublyLinkedList<T>::getTop() const {
    if (this->tail != nullptr)
    {
        Node<T>* currentNode = this->tail;
        return currentNode->data; //FIXME warning generated should we be typecasting somehow???
    }
    else // the list is empty
    {
        T nullValue;
        return nullValue;
    }
}

template class StackDoublyLinkedList<Complex>;

#endif //ASSIGNMENT3_STACKDOUBLYLINKEDLIST_H
