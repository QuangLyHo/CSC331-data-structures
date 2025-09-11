#include <iostream>
#include "arrayListType.h"

int main() {
    int size;

    cout << "Enter number items for list" << endl;
    cin >> size;

    arrayListType<double> priceList(size);
    double price;

    cout << "Please enter prices for " << size << " items: " << endl;

    for (int i = 0; i < size; i++) {
        cout << "Enter price for item " << i + 1 << ": ";
        cin >> price;
        priceList.insert(price); 
    }

    cout << "Printing price list for items:" << endl;
    priceList.print();
    cout << "Clearing list of items..." << endl << endl;
    priceList.clearList();

    arrayListType<string> animalList(3);
    string animal;

    cout << "Enter your 3 favorite animals " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "animal " << i+1 << ": ";
        cin >> animal;
        animalList.insert(animal);
    }

    cout << "Printing favorite animals..." << endl << endl;
    animalList.print();
    cout << endl;

    animalList.replaceAt(1, "rat");

    cout << "I have swapped your second favorite animal with a rat...\n";
    cout << "Printing favorite animals with rat as second favorite..." << endl;
    animalList.print();

    cout << "Printing address of list before clearing" << endl;
    animalList.listAddress();

    animalList.clearList();
    cout << endl;
    cout << "Clearing list...\n";
    cout << endl;

    cout << "Printing address of list AFTER clearing" << endl;
    animalList.listAddress();
    cout << endl;

    return 0;
}