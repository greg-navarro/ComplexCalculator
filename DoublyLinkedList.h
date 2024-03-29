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

template <class T> class DoublyLinkedList
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

//template<class T> //FIXME why is the thing wanting it here????
//DoublyLinkedList<T>::DoublyLinkedList() {
//    head = nullptr;
//    tail = nullptr;
//    size = 0;
//}

///**
// * Display a doubly linked list.
// * @tparam T
// */
//template<class T>
//void DoublyLinkedList<T>::displayList() const {
//    Node<T>* currentNode = head;
//    std::string output = ""; // fixme: are we printing???
//    int index = 1;
//    while (currentNode != nullptr)
//    {
//        std::cout << "Node " << index << ": " << currentNode->data << "\n";
//        currentNode = currentNode->next;
//        index++;
//    }
//
//    if (head == nullptr) {
//        std::cout << "EMPTY\n";
//    }
//}
//
///**
// * Add a node at the beginning of a doubly linked list.
// * @tparam T
// * @param d
// */
//template<class T>
//void DoublyLinkedList<T>::addFront(T d) {
//    Node<T>* newNode = new Node<T>;
//    newNode->data = d;
//
//    if (this->size == 0) // check if list is empty
//    {
//        tail = newNode; // tail equal new node with our new data
//    }
//    else  // if not empty
//    {
//        newNode->next = this->head;
//        head->prev = newNode; // head.prev = new node with new data
//    }
//
//    this->head = newNode; // set head pointer to the inserted node
//
//    // increment size upwards
//    size++;
//}
//
///**
// * Remove a node at the beginning of a doubly linked list.
// * @tparam T
// */
//template<class T>
//void DoublyLinkedList<T>::popFront() {
//    if (size > 0)
//    { // check list isn't empty
//        Node<T>* toRemove = head; // fixme: deallocate???
//        if (size > 1)
//        { // if there are many elements, just remove front
//            head = head->next;
//        }
//        else
//        {
//            head = nullptr;
//            tail = nullptr;
//        }
//        delete toRemove; // fixme: deallocate???
//        size -= 1;
//    }
//}
//
///**
// * Add a node at the end of a doubly linked list.
// * @tparam T
// * @param d
// */
//template<class T>
//void DoublyLinkedList<T>::addBack(T d) {
//    if (size > 0)
//    {
//        Node<T>* newTail = new Node<T>(d);
//        newTail->prev = tail;
//        tail->next = newTail;
//        tail = newTail;
//        // fixme: should I set the next* pointer of the new tail to null???
//    }
//    else
//    {
//        this->addFront(d);
//    }
//}
//
///**
// * Remove a node at the end of a doubly linked list.
// * @tparam T
// */
//template<class T>
//void DoublyLinkedList<T>::popBack() {
//    if (size > 0)
//    { // check list isn't empty
//        Node<T>* toRemove = tail; // fixme: deallocate???
//        if (size > 1)
//        { // if there are many elements, just remove back
//            tail = tail->prev;
//            *tail->next = nullptr;
//        }
//        else
//        { // if only one element, list is empty
//            head = nullptr;
//            tail = nullptr;
//        }
//        delete toRemove; // fixme: deallocate???
//        size -= 1;
//    }
//}
//
///**
// * Add a node in general.
// * @tparam T
// * @param d
// * @param iter
// */
//template<class T>
//void DoublyLinkedList<T>::addNode(T d, Node<T> *iter) {
//    // TODO add node
//}
//
//template<class T>
//void DoublyLinkedList<T>::deleteNode(T d, Node<T> *iter) {
//    // TODO delete node
//}
//
///**
// * Return size of a doubly linked list.
// * @tparam T
// * @return
// */
//template<class T>
//int DoublyLinkedList<T>::getSize() const {
//    return size;
//}
//
///**
// * Return a pointer to a node in a doubly linked list and return
// * NULL otherwise.
// * @tparam T
// * @param d
// * @return
// */
//template<class T>
//Node<T> *DoublyLinkedList<T>::findNode(T d) {
//    Node<T>* currentNode = nullptr; // fixme is nullptr the same as NULL?
//    if (size > 0) {
//        bool found = false;
//        currentNode = head;
//        while (!found && currentNode != nullptr)
//        {
//            if (currentNode->data == d)
//                found = true;
//            else
//                currentNode = currentNode->next;
//        }
//    }
//
//    return currentNode;
//}
//
///**
// * Return true if empty and false otherwise.
// * @tparam T
// * @return
// */
//template<class T>
//bool DoublyLinkedList<T>::isEmpty() const {
//    bool empty = false;
//    if (size == 0)
//        empty = true;
//    return empty;
//}





#endif //ASSIGNMENT3_DOUBLYLINKEDLIST_H
