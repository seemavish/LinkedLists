#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

struct Node
{
    int data;
    struct Node *next;

    Node(int value);
    ~Node();
};

class List
{
public:
    Node* head;

public:
    List();
    
    // copy constructor
    List(const List& original); 

    // overloaded assignment operator
    List& operator = (const List& original);

    // destructor
    ~List();

    void displayList(Node *pointer);
    bool findElement(Node *head, int value);
    void insertAtHead(Node* &head, int value);
    void insertAtTail(Node* &head, int value);
    void insertBetween(Node* &head, int value, int position);
};


#endif