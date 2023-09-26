#include "linkedList.h"

#include <iostream>
using namespace std;

Node::Node(int value)
{
    *data = value;
    next = NULL;
}

Node::~Node()
{
    delete data;
}

void List::insertBetween(Node *&head, int value, int position)
{
    Node *newNode = new Node(value);

    if (position == 0)
    {
        insertAtHead(head, value);
    }

    Node *pointer = head;
    int currentposition = 0;

    while (currentposition != position - 1)
    {
        pointer = pointer->next;
        currentposition++;
    }

    newNode->next = pointer->next;
    pointer->next = newNode;

    delete newNode;
    delete pointer;
}

void List::insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // traverse through the list until NULL found and redirect it to newNode
    Node *pointer = head;
    while (pointer != NULL)
    {
        pointer = pointer->next;
    }

    pointer->next = newNode;

    delete newNode;
    delete pointer;
}

void List::insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;

    delete newNode;
}

void List::displayList(Node *head)
{
    // pointer traverses through the entire list starting from head until reaches NULL
    Node *pointer = head;
    while (pointer != NULL)
    {
        cout << pointer->data << " -> " << endl;
        pointer = pointer->next;
    }

    cout << "NULL" << endl;

    delete pointer;
}

bool List::findElement(Node *head, int value)
{
    Node *pointer = head;

    while (pointer != NULL)
    {
        if (*pointer->data == value)
        {
            return true;
        }
        pointer = pointer->next;
    }

    return false;
}