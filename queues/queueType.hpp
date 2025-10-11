#pragma once

#include <iostream>
#include <cassert>
#include "queueADT.hpp"

using namespace std;

template <class Type>
class queueType: public queueADT<Type> {
private:
    int count;  //store # of elements in queue
    int queueFront; //points to first element in queue
    int queueRear;  //points to last element in queue
    int maxQueueSize;   //stores max queue size
    Type *list; //pointer to array of queue elements
public:
    const queueType<Type>& operator=(const queueType<Type>&);
        //Overload the assignment operator
    bool isEmptyQueue() const;
        //Function to determine whether the queue is empty
        //Postcondition: Returns true is queue is empty,
            //otherwise returns false
    bool isFullQueue() const;
        //Function to determin whether the queue is full
        //Postcondition: Returns true if queue is full
            //otherwise returns false
    void initializeQueue();
        //Function to init the queue to empty state
        //Postcondition: The queue is empty
    Type front() const;
        //Function to return first element of queue
        //Precondition: queue exists and is not empty
        //Postcondition: if empter, program terminates;
            //otherwise, first ele of queue is returned
    Type back() const;
        //Function to return the last ele of queue
        //Precondition: queue exists and is not empty
        //Postcondition: if empty, program terminates
            //otherwise, last element of queue returned
    void addQueue(const Type& queueElement);
        //Function to add queueElement to the queue
        //Precondition: the queue exists and not full
        //Postcondition: the queue is changed and queueElement is
            //added to the queue
    void deleteQueue();
        //Function to remove the first element of queue
        //Precondition: queue exists and is not empty
        //Postcondition: queue is changed and first element 
            //is removed from the queue
    queueType(int queueSize = 100);
        //Constructor
    queueType(const queueType<Type>& otherQueue);
        //Copy constructor
    ~queueType();
        //Destructor
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const {
    return (count == 0);
}

template <class Type>
bool queueType<Type>::isFullQueue() const {
    return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::initializeQueue() {
    count = 0;
    queueFront = 0;
    queueRear = maxQueueSize - 1;
}

template <class Type>
Type queueType<Type>::front() const {
    assert(!isEmptyQueue());
    return (list[queueFront]);
}

template <class Type>
Type queueType<Type>::back() const {
    assert(!isEmptyQueue());
    return (list[queueRear]);
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement) {
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;
        count++;
        list[queueRear] = newElement;
    }
    else {
        cout << "Cannot add to a full queue." << endl;
    }
}

template <class Type>
void queueType<Type>::deleteQueue() {
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;
    }
    else {
        cout << "Cannot remove from an empty queue." << endl;
    }
}

template <class Type>
queueType<Type>::queueType(int queueSize) {
    if (queueSize <= 0) {
        cout << "Invalid size." << endl;
        cout << "Array size 100." << endl;

        maxQueueSize = 100;
    }
    else {
        maxQueueSize = queueSize;

        queueFront = 0;
        queueRear = maxQueueSize - 1;
        count = 0;
        list = new Type[maxQueueSize];
    }
}

template <class Type>
queueType<Type>::~queueType() {
    delete [] list;
}

//Copy constructor
template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue) {
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    count = otherQueue.count;

    list = new Type[maxQueueSize];
    assert(list != NULL);

    for (int i = 0; i < maxQueueSize; i++) {
        list[i] = otherQueue.list[i];
    }
}

//Overloading assignment operator
template <class Type>
const queueType<Type>& queueType<Type>::operator=
                                    (const queueType<Type>& otherQueue) {
    if (this != &otherQueue) {
        delete [] list;

        maxQueueSize = otherQueue.maxQueueSize;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        count = otherQueue.count;

        list = new Type[maxQueueSize];
        assert(list != NULL);

        for (int i = 0; i < maxQueueSize; i++) {
            list[i] = otherQueue.list[i];
        }


    }

    return *this;
}




