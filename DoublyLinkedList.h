/*
Name: Gregory Litman-Navarro
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program:
Last updated:
*/

#ifndef ASSIGNMENT3_DOUBLYLINKEDLIST_H
#define ASSIGNMENT3_DOUBLYLINKEDLIST_H

#include "Node.h"

template <class T>
class DoublyLinkedList
{
protected:
    Node<T>* head; //pointer to the first node of a doubly linked list
    Node<T>* tail; //pointer to the last node of a doubly linked list
    int size; //size of a doubly linked list
public:
    DoublyLinkedList();
    void addFront(T d); //add a node at the beginning of a doubly linked list
    void popFront(); //remove a node at the beginning of a doubly linked list
    void addBack(T d); // add a node at the end of a doubly linked list
    void popBack(); // remove a node at the end of a doubly linked list
    void addNode(T d, Node<T>* iter); //add a node in general
    void deleteNode(T d, Node<T>* iter); //delete a node in general
    Node<T>* findNode(T d); //return a pointer to a node in a doubly linked list and return NULL otherwise
    int getSize() const; //return size of a doubly linked list
    bool isEmpty() const; //return true if empty and false otherwise
    void displayList() const; // display a doubly linked list
};




#endif //ASSIGNMENT3_DOUBLYLINKEDLIST_H
