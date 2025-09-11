#include <iostream>
#include "unorderedLinkedListType.h"
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
    dList->insertFirst(12.43);
    dList->insertFirst(22.34);
    dList->insertFirst(75.43);
    dList->insertFirst(3.77);
    dList->insertFirst(2.39);
    dList->insertFirst(8.92);
    dList->insertFirst(73.21);
    dList->insertFirst(41.38);
    dList->insertFirst(11.10);

    cout << "Printing list: " << endl;
    dList->print();
    cout << endl;

    cout << "***** Deleting 75.45, which is not in the list *****" << endl;
    dList->deleteNode(75.45);

    dList->deleteNode(75.43);

    cout << "Deleting 75.43" << endl;
    cout << "Printing updated list; after 75.43 was deleted" << endl;
    dList->print();

    cout << endl;

    


    return 0;
}