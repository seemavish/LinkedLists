#include "linkedList.h"

#include <iostream>
#include <stdexcept>
using namespace std;

Node::Node(int value)
{
    data = value;
    next = nullptr;
}

Node::~Node(){};

void List::displayList(Node *head)
{
    // pointer traverses through the entire list starting from head until reaches NULL
    Node *pointer = head;
    while (pointer != nullptr)
    {
        cout << pointer->data << " -> ";
        pointer = pointer->next;
    }

    cout << "NULL" << endl;
}

bool List::findElement(Node *head, int value)
{
    Node *pointer = head;

    while (pointer != nullptr)
    {
        if (pointer->data == value)
        {
            return true;
        }
        pointer = pointer->next;
    }

    return false;
}

void List::insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void List::insertBetween(Node *&head, int value, int position)
{
    if(position < 0){
        invalid_argument("Invalid position");
    }

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
}

void List::insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // traverse through the list until NULL found and redirect it to newNode
    Node *pointer = head;
    while (pointer->next != nullptr)
    {
        pointer = pointer->next;
    }

    pointer->next = newNode;
}

List::List(){
    head = nullptr;
}

List::List(const List &original)
{
    Node *pointer = original.head;

    while (pointer != nullptr)
    {
        insertAtTail(head, pointer->data);
        pointer = pointer->next;
    }
}

List::~List()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

List &List::operator=(const List &original)
{
    // check for self-assignment
    if (this != &original)
    {

        Node *current = head;

        // clean the list
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

        // initialize an empty list
        head = nullptr;

        Node *pointer = original.head;
        while (pointer != nullptr)
        {
            insertAtTail(current, pointer->data);
            pointer = pointer->next;
        }
    }
    return *this;
}
