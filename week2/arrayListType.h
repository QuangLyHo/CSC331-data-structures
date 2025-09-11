#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
//*****************************************************
// This source code is obtained from the textbook
// Author: D.S. Malik
// Note that class definition and function definitions 
// are defined in the header file as this we these
// are templates. (See page 112-113 2nd Edition, Malik
//*****************************************************
template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator= (const arrayListType<elemType>&);
	  //Overloads the assignment operator
	bool isEmpty() const;
	  //Function to determine whether the list is empty
	  //Postcondition: Returns true if the list is empty;
	  //	otherwise, returns false.
	bool isFull() const;
	  //Function to determine whether the list is full.
	  //Postcondition: Returns true if the list is full;
	  //	otherwise, returns false.
	int listSize() const;
	  //Function to determine the number of elements in the list
	  //Postcondition: Returns the value of length.
	int maxListSize() const;
	  //Function to determine the size of the list.
	  //Postcondtion: Returns the value of maxSize.
	void print() const;
	  //Function to output the elements of the list.
	  //Postcondition: Elements of the list are output on the standard output device.
	bool isItemAtEqual(int location, const elemType& item) const;
	  //Function to determine whether the item is the same as the item in the list at the position specified by
	  //Postcondtion: Returns true if list[location] is the same as the item;
	  //	otherwise, returns false;
	void insertAt(int location, const elemType& insertItem);
	  //Function to insert an item in the list at the position specified by location.
	  //The item to be inserted is passed as a parameter to the function.
	  //Postcondition: Starting at the location, the elements of the list
	  //	are shifted down, list[location] = insertItem;
	  //	and length++;. If the list is full or location is out of range,
	  //	an appropriate message is displayed.
	void insertEnd(const elemType& insertItem);
	  //Function to insert an item at the end of the list.
	  //The parameter insertItem specifies the item to be inserted.
	  //Postcondition: list[length] = insertItem; and length++;
	  //	If the list is full, an appropriate message is displayed.
	void removeAt(int location);
	  //Function to remove the item from the list at the position
	  //specified by location
	  //Postcondition: The list element at list[location] is removed
	  //	and length is decremented by 1.  If location is out of
	  //	range, an appropriate message is displayed.
	void retrieveAt(int location, elemType& retItem) const;
	  //Function to retrieve the element from the list at the position
	  //specified by location.
	  //Postcondition: retItem = list[location]
	  //	If location is out of range, an appropriate message is displayed.
	void replaceAt(int location, const elemType& repItem);

	void clearList();

	int seqSearch(const elemType& item) const;

	void insert(const elemType& insertItem);

	void remove(const elemType& removeItem);

	arrayListType(int size = 100);
	  //constructor
	  //Creates an array of the size specified by the parameter size.
	  //The default array size is 100.
	  //Postcondition:  The list points to the array, length = 0, and maxSize = size

	arrayListType(const arrayListType<elemType>& otherList);
	  //copy constructor

	~arrayListType();
	  //destructor
	  //Deallocates the memory occupied by the array.

	  //get list address
	  void listAddress() {
		cout << &list;
	  }

protected:
	elemType* list;		//array to hold the list elements
	int length;			//to store the length of the list
	int maxSize;		//to store the maximum size of the list

};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
};

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
};

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
};

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
};

template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		std::cout << list[i] << " ";
	cout << endl;
};

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
	return(list[location] == item);
};

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "
		<< "is out of range" << endl;
	else
		if (length >= maxSize)  // list is full
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];	//move the elements down

			list[location] = insertItem;	//insert the item at the specified position
			length++;						//increment the length
		}
};  //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize)	//the list is full
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem;	//insert the item at the end
		length++;					//increment the length
	}
};  //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed is out of range" << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];

		length--;
	}
};  //end removeAt
template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is " << "out of range." << endl;
	else
		retItem = list[location];
};  //end retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is "
		<< "out of range." << endl;
	else
		list[location] = repItem;
};  //end replactAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
};  //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive.  Creating "
			<< "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);   // research this
};

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete[] list;
};

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize];	//create the array
	assert(list != NULL);			//terminate if unable to allocate
									//memory space
	for (int j = 0; j < length; j++)
		list[j] = otherList.list[j];
}; // copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList)
{
	if (this != &otherList)		//avoid self-assignment
	{
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new elemType[maxSize];	// create the array
		assert(list != NULL);			// if unable to allocate memory
										// space, terminate the program
			for (int i = 0; i < length; i++)
				list[i] = otherList.list[i];
	}
	return *this;
};

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
};  //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int inc;

	if (length == 0)	//list is empty
		list[length++] = insertItem;	//insert the item and increment the length
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		inc = seqSearch(insertItem);
		if (inc == -1)	//the item to be inserted does not exist in the list
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list.  No duplicates are allowed." << endl;
	}
};  //end insert

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;
	if (length == 0)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
};  //end remove