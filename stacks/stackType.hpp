//
//  stackType.hpp
//  stackApp
//
//  Created by Quang Ly Ho on 9/16/25.
//

// #pragma once

// #include <stdio.h>
// #include <iostream>
// #include "stackADT.hpp"

// using namespace std;

// template <class Type>
// class stackType: public stackADT<Type>
// {
// private:
//     int maxStackSize;
//     int stackTop;
//     Type* list;

//     void copyStack(const stackType<Type>&);
// public:
//     const stackType<Type>& operator=(const stackType<Type>&);
//     void initializeStack();
//     bool isEmptyStack() const;
//     bool isFullStack() const;
//     void push(const Type&);
//     void push(const Type&);
//     Type top() const;
//     void pop();
//     stackType(int stackSize = 100);
//     stackType(const stackType<Type>&);
//     ~stackType();
// };

// template <class Type>
// void stackType<Type>::initializeStack() {
//     stackTop = 0;
// }

// template <class Type>
// bool stackType<Type>::isEmptyStack() const {
//     return (stackTop == 0);
// }

// template <class Type>
// bool stackType<Type>::isFullStack() const {
//     return (stackTop == maxStackSize);
// }

// template <class Type>
// void push(const Type& newItem) {
//     if (!isFullStack) {
//         list[stackTop] = newItem;
//         stackTop++;
//     } 
//     else {
//         cout << "Cannot add to a full stack." << endl;
//     }
// }

// template <class Type>
// Type stackType<Type>::top() const {
//     assert(stackTop != 0);

//     return list[stackTop - 1];
// }

// template <class Type>
// void stackType<Type>::pop() {
//     if (!isEmptyStack) {
//         stackTop--;
//     } 
//     else {
//         cout << "The stack is empty" << endl;
//     }
// }

// template <class Type>
// void stackType<Type>::copyStack(const stackType& otherStack) {
//     delete [] list;
//     maxStackSize = otherStack.maxStackSize;
//     stackTop = otherStack.stackTop;

//     list = new Type[maxStackSize];
//     for (int i = 0; i < stackTop; i++) {
//         list[i] = otherstack.list[i];
//     }
// }

// template <class Type>
// stackType<Type>::stackType(int stackSize) {
//     if (stackSize <= 0) {
//         cout << "StackSize cannot be negative or 0" << endl;
//         maxStackSize = 100;
//     } 
//     else {
//         maxStackSize = stackSize;
//     }

//     stackTop = 0;
//     list = new Type[maxStackSize];
// }

// template <class Type>
// stackType<Type>::~stackType() {
//     delete [] list;
// }

// template <class Type>
// stackType<Type>::stackType(const stackType& otherStack) {
//     list = NULL;

//     copyStack(otherStack);
// }

// template <class Type>
// const stackType<Type>& stackType<Type>::operator=
//     (const stackType<Type>& otherStack) {
//     if (this != otherStack) {
//         copyStack(otherStack);
//     }

//     return *this;
// }











#ifndef stackType_hpp
#define stackType_hpp

#include <stdio.h>
#include <iostream>
#include "stackADT.hpp"
using namespace std;

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
    //Overload the assignment operator.
    
    void initializeStack();
    //Function to insitialize the stack to an empty state.
    //Postcondition: stackTop = 0;
    
    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty,
    //     otherwise returns false.
    
    bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns true if the stack is full,
    //     otherwise returns false
    
    void push(const Type& newItem);
    //Function to add newItem to the stack.
    //Precondition:  The stack exists and is not full.
    //Postcondition: The stack is changed and newItem is
    //     added to the top fo the stack.
    
    Type top() const;
    //Function to return the top element of the stack.
    //Precondition:  The stack exists and is not empty
    //Postcondition: If the stack is empty the program
    //     terminates; otherwise, the top element of the stack
    //     is returned.
    
    void pop();
    //Function to remove the top element of the stack.
    //Precondition:  The stack exists and is not empty.
    //Postcondition: The stack is changed and the top element is
    //     removed from the stack.
    
    stackType(int stackSize = 100);
    //Constructor
    //Create an array of the size stackSize to hold
    //the stack elements.  The default stack size is 100.
    //Postcondition:  The variable list contains the base address
    //   of the array, stackTop = 0, and maxStackSize = stackSize
    
    stackType(const stackType<Type>& otherStack);
    //Copy constructor
    
    ~stackType();
    //Destructor
    //Remove all the elements from the stack.
    //Postcondition:  The array (list) holding the stack
    //   elements is deleted.
    
private:
    int maxStackSize;   //variable to store the maximum stack size
    int stackTop;       //variable to point to the top of the stack
    Type *list; //pointer to the array that holds the stack elements
    
    void copyStack(const stackType<Type>& otherStack);
    //Function to make a copy of otherStack
    //Postcondition:  A copy of otherStack is created and asssigned
    //   to this stack.
};

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
}


template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    //copy other stack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
}

template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of th earray to hold the stack must "
        << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to the value
                                    //specified by the parameter stackSize
    
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType()   //destructor
{
    delete [] list;     //deallocate the memory occupied by the array
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;
    copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);
    
    return *this;
}

//Virtual Functions
template <class Type>
void stackType<Type>::push(const Type& newItem) 
{
    if (!isFullStack()) 
    {
        list[stackTop] = newItem;   // add new item at the top
        stackTop++; //increment stacktop
    }
    else 
    {
        cout << "Cannot add to a full stack." << endl;
    }
}

template <class Type>
Type stackType<Type>::top() const 
    //Function to return the top element of the stack.
    //Precondition:  The stack exists and is not empty
    //Postcondition: If the stack is empty the program
    //     terminates; otherwise, the top element of the stack
    //     is returned.
{
    assert(stackTop != 0); //if stack is empty, terminate the program

    return list[stackTop - 1];  //return the elmnt of the stack indeicated
                                // by stackTop - 1
}

template <class Type>
void stackType<Type>::pop() 
    //Function to remove the top element of the stack.
    //Precondition:  The stack exists and is not empty.
    //Postcondition: The stack is changed and the top element is
    //     removed from the stack.
{
    if (!isEmptyStack())
    {
        stackTop--;
    }
    else
    {
        cout << "Cannot remove from an empty stack." << endl;
    }
}




#endif /* stackType_hpp */
