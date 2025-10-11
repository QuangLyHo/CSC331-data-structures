//
//  stackADT.hpp
//  stackApp
//
//  Created by Quang Ly Ho on 9/23/25.
//
//****************************************************************
// Author:  Quang Ly Ho
// This class specifies the basic operations on a stack.
//****************************************************************
#include "stackADT.hpp"
#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType: public stackADT<Type> {
private:
    nodeType<Type> *stackTop;   //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack);
        //Function to make a copy of otherStack
        //Postcondition: a copy of the otherStack is created and 
            //assigned to this stack
public:
    const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
        //Overload assignment operator
    bool isEmptyStack() const;
        //Function to determine whether stack is empty
        //Postcondition: returns true if empty;
            //otherwise returns false
    bool isFullStack() const;
        //Function to determine whether stack is full
        //Postcondition: returns false
    void initializeStack();
        //Function to initialize the stack to an empty state
        //Postcondition: the stack elements are removed;
            //stackTop = NULL
    void push(const Type&);
        //Function to add newItem to the stack
        //Precondition: the stack exists and is not full
        //Postcondition: the stack is changed and newItem is 
            //added to the top of the stack
    Type top() const;
        //Function to return the top element of the stack
        //Precondition: the stack exists and is not empty
        //Postcondition: if the stack is empty, the program
            //terminates; otherwise, the top element of
            //the stack is returned
    void pop();
        //Function to remove the top element of the stack
        //Precondition: the stack exists and is not empty
        //Postcondition: the stack is changed and the top element
            //is removed from the stack
    linkedStackType();
        //Default constructor
        //Postcondition: stackTop = NULL;
    linkedStackType(const linkedStackType<Type>&);
        //Copy constructor
    ~linkedStackType();
        //Destructor
        //Postcondition: all the elements of the stack are removed
};

template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const {
    return (stackTop == NULL);
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const {
    return false;
}

template <class Type>
void linkedStackType<Type>::initializeStack() {
    nodeType<Type> *temp; //pointer to delete the node

    //while there are elmts in stack
    while (stackTop != NULL) { 
        temp = stackTop;    //temp points to cur node
        stackTop = stackTop->link;  //stackTop points to next node
        delete temp;    //deallocate memory occupied by temp
    }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem) {
    nodeType<Type> *newNode;  //pointer to create new node

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newItem;    //store newItem in node
    newNode->link = stackTop;   //insert newNode before stackTop
    stackTop = newNode; //set stackTop to point to the newly added node
}

template <class Type>
Type linkedStackType<Type>::top() const {
    assert(stackTop != NULL);
    return stackTop->info;
}

template <class Type>
void linkedStackType<Type>::pop() {
    nodeType<Type> *temp;

    if (stackTop != NULL) {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp; 
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void linkedStackType<Type>::copyStack
                            (const linkedStackType<Type>& otherStack) {
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL) 
        initializeStack();
    
    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    
    else {
        current = otherStack.stackTop;

        stackTop = new nodeType<Type>;
        
        stackTop->info = current->info;
        stackTop->link = NULL;
        last = stackTop;
        current = current->link;
    }
    while (current != NULL) {
        newNode = new nodeType<Type>;

        newNode->info = current->info;
        newNode->link = NULL;
        last->link = newNode;
        last = newNode;
        current = current->link;
    }
}

template <class Type>
linkedStackType<Type>::linkedStackType
                            (const linkedStackType<Type>&otherStack) {
    stackTop = NULL;
    copyStack(otherStack);
}

template <class Type>
linkedStackType<Type>::~linkedStackType() {
    initializeStack();
}

template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=
                    (const linkedStackType<Type>& otherStack) {
    if (this != &otherStack) 
        copyStack(otherStack);
    
    return *this;
}