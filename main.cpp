#include "linkedList.h"

#include <iostream>
using namespace std;

int main(){
    List list1;

    // Node* head = new Node(0);

    list1.insertAtHead(list1.head, 10);
    list1.insertAtHead(list1.head, 20);
    list1.insertBetween(list1.head, 50, 1);

    cout << "Original list : "; 
    list1.displayList(list1.head);
    cout <<endl;

    // create a copy of original list using copy constructor
    List list2(list1);

    cout << "Copy constructor created for the original list : ";
    list2.displayList(list2.head);

    // modify the original list
    list1.insertBetween(list1.head, 30, 2);
    list1.insertAtTail(list1.head, 75);

    cout << "Modified original list : ";
    list1.displayList(list1.head);

    // copied list after modifying the original list
    cout << "Copy constructor list remains the same : ";
    list2.displayList(list2.head);
    cout <<endl;

    // copy the list using overloaded operator
    List list3;

    list3 = list1;

    cout << "Original list copied using assignment operator : ";
    list3.displayList(list3.head);

    // modify the original list 
    list1.insertAtHead(list1.head, 4);

    cout << "Modified original list again : ";
    list1.displayList(list1.head);

    // display copied list using =
    cout << "Assigned list remains the same : ";
    list3.displayList(list3.head);
    
    // list2.findElement(list2.head, 5);

    return 0;
};