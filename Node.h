/*
Name: Gregory Litman-Navarro
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program:
Last updated:
*/

#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H

template <class T>
struct Node {
    T data; //data of a node
    Node *prev; //pointer to previous node
    Node *next; //pointer to next node };
};

#endif //ASSIGNMENT3_NODE_H
