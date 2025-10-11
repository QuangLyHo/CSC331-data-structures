#include <iostream>
#include "unorderedLinkedListType.h"
#include "orderedLinkedListType.h"
using namespace std;

int main() {
    unorderedLinkedList<double>* dList = new unorderedLinkedList<double>;
    double num;

    cout << "Line 9: Enter decimal digits: " << endl;
    cin >> num;

    dList->insertFirst(num);

    cout << "Line 14: Enter decimal digits: " << endl;
    cin >> num;

    dList->insertFirst(num);
    dList->insertFirst(12.03);
    dList->insertFirst(22.02);
    dList->insertFirst(75.03);
    dList->insertFirst(3.01);
    dList->insertFirst(2.01);
    dList->insertFirst(8.02);
    dList->insertFirst(73.01);
    dList->insertFirst(41.01);
    dList->insertFirst(11.01);

    cout << "Printing list: " << endl;
    dList->print();

    cout << endl;

    cout << "***** Deleting 75.45, which is not in the list *****" << endl << endl;
    dList->deleteNode(75.45);

    dList->deleteNode(75.43);

    cout << "Deleting 75.43" << endl;
    cout << "Printing updated list; after 75.43 was deleted" << endl;
    dList->print();

    cout << endl;
    cout << endl;

    double total;
    double subTotal;

    for (linkedListIterator<double> front = dList->begin(); front != dList->end();++front) 
        total += *front;

    subTotal = static_cast<int> (total);

    cout    << "This is the subtotal: " 
            << subTotal 
            << "\nThis is the total: " 
            << total 
            << endl;
    
    delete dList;
    dList = nullptr;

    orderedLinkedList<int> *ordList = new orderedLinkedList<int>;

    ordList->insert(10);
    ordList->insert(20);
    ordList->insert(30);
    ordList->insert(40);
    ordList->insert(50);
    ordList->insert(60);
    ordList->insert(70);
    ordList->insert(80);

    ordList->print();

    cout << endl;
    cout << "Deleting 10" << endl;

    ordList->deleteNode(10);

    ordList->print();
    cout << endl;
    cout << endl;
    ordList->toCall();


    return 0;
}