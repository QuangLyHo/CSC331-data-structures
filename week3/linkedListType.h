//*************************************************************
// Author: Quang Ly Ho
// 
// This class specifies the members to implement the basic properties
// of a linked list. This is an abstract class. 
// We cannot instantiate an object of this class.
//*************************************************************
#pragma once

#include <iostream>
#include "string"
#include "nodeType.h"
#include "linkedListIterator.h"
#include "cassert"

using namespace std;

template <class Type>
class linkedListType {
private:
    void copyList(const linkedListType<Type>& otherList);
        //Function to make a copy of otherList.
        //Postcondition: A copy of otherList is created and assigned
        //  to this list.
protected:
    int count; //variable to store the number of list elements
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last; // pointer to the last node of the list
public: 
    const linkedListType<Type>& operator= (const linkedListType<Type>&);
        //Overload the assignment operator
    void initializeList();
        //initialize the list to an empty state
        //postcondition: first = NULL, last = NULL, count = 0
    bool isEmptyList() const;
        //function to determin whether the list is empty
        //postcondition: returns true if the list is empty, otherwise
        //  it returns false
    void print() const;
        //function to output the data contained in each node
        //postcondition: none
    int length() const;
        //function to return the number of nodes in the list
        //postcondition: the value of count is returned
    void destroyList();
        //function to delete all the nodes from the list
        //postcondition: first = NULL, last = NULL, count = 0
    Type front() const;
        //function to return the first element of the list
        //precondition: the list must exist and must not be empty
        //postcondition: if the list is empty, the program terminates;
        //  otherwise, the first element of the list is returned
    Type back() const;
        //function to return the last element of the list
        //precondition: the list must exist and must not be empty
        //postcondition: if the list is empty, the program
        //  terminate; otherwise, the last element of the list
        //  is returned
    virtual bool search(const Type&) const = 0;
        //function to determine whether searchItem is in the list
        //postcondition: returns true if searchItem is in the list,
        //  otherwise the value false is returned
    virtual void insertFirst(const Type&) = 0;
        //function to insert newItem at the beginning of the list
        //postcondition: first points to the new list, newItem is
        //  inserted at the beginning of the list, last points to the
        //  last node in the list, and count is incremented by 1
    virtual void insertLast(const Type&) = 0;
        //function to insert newItem at the end of the list
        //postcondition: first points to the new listm newItem is
        //  inserted at the end of the list, last points to the last
        //  node in the list, and count is incremented by 1
    virtual void deleteNode(const Type&) = 0;
        //function to delete deleteItem from the list
        //postcondition: if found, the node containing deleteItem is
        //  deleted from the list. first points to the first node,
        //  last points to the last node of the updated list, and
        //  count is decremented by 1
    linkedListIterator<Type> begin();
        //function to return an iterator at the beginning of the
        //  linked list
        //postcondition: returns an iterator such that current is set
        //  to first
    linkedListIterator<Type> end();
        //function to return an iterator one element past the
        //  last element of the linked list
        //postcondition: returns an iterator such that current is set to NULL
    linkedListType();
        //default constructor
        //initializes the list to an empty state
        //postcondition: first = NULL, last = NULL, count = 0
    linkedListType(const linkedListType<Type>&);
        //copy constructor
    ~linkedListType();
        //destructor
        //deletes all the nodes from the list
        //postcondition: the list object is destroy
    //Get first function
    nodeType<Type> getFirst() const {
        return head;
    }
};

template <class Type>
linkedListType<Type>::linkedListType() // default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first!= NULL)    //while there are nodes in the list
    {
        temp = first;           //set temop to the current node
        first = first->link;    //advance first to the next node
        delete temp;        //deallocate the memory occupied by temp
    }

    last = NULL;    //init last to NULL; first has already
                    //been set to NULL by the while loop

    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();  //if the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;    //pointer to the first node

    current = first;    //set current pointer to the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const 
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);

    return first->info; //return the info of the first node
}

template <class Type>
Type linkedListType<Type>::back() const 
{
    assert (last != NULL);

    return last->info;  //return the info of the last node
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin() 
{
    linkedListIterator<Type> temp(first);

    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);

    return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) 
{
    nodeType<Type> *newNode;    //pointer to create a node
    nodeType<Type> *current;    //pointer to traverse the list

    if (first != NULL)  //if the list is nonempty, make it empty
        destroyList();
    
    if (otherList.first == NULL)    //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else 
    {
        current = otherList.first;  //current points to the
                                    //list to be copied
        count = otherList.count;

            //copy the first node
        first = new nodeType<Type>;  //create a node
        first->info = current->info;    //copy the info
        first->link = NULL; //set the link field of the node to NULL
        last = first;   //make last point to the first node
        current = current->link;    //make current point to the next node

            //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;   //create a node
            newNode->info = current->info;  //copy the info
            newNode->link = NULL;   //set the link of the newNode to NULL
            last->link = newNode;   //attach newNode after last
            last = newNode; //make last point to the actual last node
            current = current->link;    //make current point to the next node
        }//end while
    }//end else
}

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}

    //copy constructor
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) 
{
    first = NULL;   
    copyList(otherList);
}

    //overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList) 
{
    if (this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}


