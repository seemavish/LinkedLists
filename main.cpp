#include "linkedList.h"

#include <iostream>
using namespace std;

int main(){
    List list1;

    Node* head = new Node(0);

    list1.insertAtHead(head, 23);
    list1.insertAtHead(head, 34);
    list1.insertBetween(head, 50, 2);

    cout << "Displaying list1: "; 
    list1.displayList(head);

    List list2;

    list2 = list1;
    list2.insertBetween(head, 3, 3);

    cout << "Displaying list2: ";
    list2.displayList(head);

    list2.findElement(head, 5);

    return 0;
};