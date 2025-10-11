#include <iostream>
#include "linkedStackType.hpp"
using namespace std;

void testCopy(linkedStackType<int>);

int main() {

    linkedStackType<int> stack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;

    stack.push(34);
    stack.push(10);
    stack.push(2);

    newStack = stack;

    cout << "After the assignment operator, newStack: " << endl;

    while (!newStack.isEmptyStack()) {
        cout << newStack.top() << endl;
        newStack.pop();
    }

    otherStack = stack;

    cout << "Testing the copy constructor." << endl;

    testCopy(otherStack);

    cout << "After the copy constructor, otherStack: "<< endl;

    while (!otherStack.isEmptyStack()) {
        cout << otherStack.top() << endl;
        otherStack.pop();
    }

    return 0;
}

void testCopy(linkedStackType<int> oStack) {
    cout << "Stack in the function testCopy:" << endl;

    while (!oStack.isEmptyStack()) {
        cout << oStack.top() << endl;
        oStack.pop();
    }
}