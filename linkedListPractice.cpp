#include <iostream>
using namespace std;

struct nodeType {
    int info;
    nodeType *link;
};

int main() {
    nodeType *first, *newNode;
    // nodeType *last;
    int num;

    cout << "Enter a list of numbers ending with -9: " << endl;
    cin >> num;
    first = NULL;

    while (num != -9) {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = first;

        first = newNode;
        cin >> num;
    }

    nodeType *it = first;

    while (it != NULL) {
        nodeType *temp = it;
        cout << it->info << " ";
        it = it->link;
        delete temp;
    }


    return 0;
}