#ifndef POINTER_LIST_H_
#define POINTER_LIST_H_

#include "helper.h"
#include <iostream>

template <typename T> class POINTER_LIST{
	private:
		cell<T>* header;
	public:

		POINTER_LIST();
		cell<T>* FIRST();
		cell<T>* END();
		cell<T>* LOCATE(T);
		T RETRIEVE(cell<T>*);
		void INSERT(T, cell<T>*);
		void DELETE(cell<T>*);
		cell<T>* NEXT(cell<T>*);
		cell<T>* PREVIOUS(cell<T>*);
		void MAKENULL();
		void append_beginning(T);
		void print();
};

#endif /* POINTER_LIST_H_ */

//The header points to the first actual cell of the list
template <typename T> POINTER_LIST<T>::POINTER_LIST()
{
	header = new cell<T>;
	header->next = nullptr;
}

//Since position is a pointer to a cell that contains a pointer to the
//desired cell,
//We return header, since this fits the criteria
template <typename T> cell<T>* POINTER_LIST<T>::FIRST()
{
	return header;
}

//End is a pointer to the last cell on the list. The last cell on the list
//Is defined as the cell that points to null
template <typename T> cell<T>* POINTER_LIST<T>::END()
{
	cell<T>* cur = header;
	while(cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}

//Insert after the cell pointed to by position, since position means the
//cell that points to the desired cell.
template <typename T> void POINTER_LIST<T>::INSERT(T e, cell<T>* position)
{
	cell<T>* temp = position->next;

	cell<T>* temp2 = new cell<T>;
	temp2->element = e;

	position->next=temp2;
	temp2->next = temp;
}

//Get the element in the next cell
template <typename T> T POINTER_LIST<T>::RETRIEVE(cell<T>* position)
{
	return position->next->element;
}

//Get pointer to the cell that points to the cell with element 'x'
template <typename T> cell<T>* POINTER_LIST<T>::LOCATE(T x)
{
	cell<T>* cur = header;
	while(cur->next != nullptr)
	{
		if(cur->next->element == x)
			return cur;
		cur = cur->next;
	}
	return cur;
}

//Delete the cell pointed to by the cell that position points to
template <typename T> void POINTER_LIST<T>::DELETE(cell<T>* position)
{
	position->next = position->next->next;
}

//Get the pointer to the cell, that the cell that position points to, points
//to
template <typename T> cell<T>* POINTER_LIST<T>::NEXT(cell<T>* position)
{
	return position->next;
}

//Get the pointer to the cell that points at the cell pointed to by position
template <typename T> cell<T>* POINTER_LIST<T>::PREVIOUS(cell<T>* position)
{
	cell<T>* cur = header;
	while(cur->next != position)
	{
		cur = cur->next;
	}
	return cur;
}

//Make the list null
template <typename T> void POINTER_LIST<T>::MAKENULL()
{
	header->next = nullptr;
}

//Debugging function. Please ignore for grading HW1
template <typename T> void POINTER_LIST<T>::append_beginning(T e)
{
	cell<T>* temp = new cell<T>;
	temp->element = e;
	temp->next = nullptr;

	if(header->next == nullptr)
	{
		header->next = temp;
	}
	else
	{
		cell<T>* old_first_element = header->next;
		header->next = temp;
		temp->next = old_first_element;
	}
}

//Another debugging function. Please ignore for HW1
template <typename T> void POINTER_LIST<T>::print()
{
	cell<T>* cur = header->next;
	while(cur != nullptr)
	{
		std::cout << cur->element << std::endl;
		std::cout << cur->next << std::endl << std::endl;
		cur = cur->next;
	}
}
