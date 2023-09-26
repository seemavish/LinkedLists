#include "linkedList.h"

#include <iostream>
using namespace std;

int main(){
    List newList;

    Node* head = new Node(0);

    newList.insertAtHead(head, 23);
    newList.insertAtTail(head, 34);
    newList.displayList(head);

    return 0;
};