#ifndef POINTER_LIST_H_
#define POINTER_LIST_H_

#include "helper.h"
#include <iostream>

template <typename T> class POINTER_LIST{
	private:
		helper<T>* header;
	public:

		POINTER_LIST();
		helper<T>* FIRST();
		helper<T>* END();
		helper<T>* LOCATE(T);
		T RETRIEVE(helper<T>*);
		void INSERT(T, helper<T>*);
		void DELETE(helper<T>*);
		helper<T>* NEXT(helper<T>*);
		helper<T>* PREVIOUS(helper<T>*);
		void MAKENULL();
		void append_beginning(T);
		void print();
};

#endif /* POINTER_LIST_H_ */

//The header points to the first actual helper of the list
template <typename T> POINTER_LIST<T>::POINTER_LIST()
{
	header = new helper<T>;
	header->next = nullptr;
}

//Since position is a pointer to a helper that contains a pointer to the
//desired helper,
//We return header, since this fits the criteria
template <typename T> helper<T>* POINTER_LIST<T>::FIRST()
{
	return header;
}

//End is a pointer to the last helper on the list. The last helper on the list
//Is defined as the helper that points to null
template <typename T> helper<T>* POINTER_LIST<T>::END()
{
	helper<T>* cur = header;
	while(cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}

//Insert after the helper pointed to by position, since position means the
//helper that points to the desired helper.
template <typename T> void POINTER_LIST<T>::INSERT(T e, helper<T>* position)
{
	helper<T>* temp = position->next;

	helper<T>* temp2 = new helper<T>;
	temp2->element = e;

	position->next=temp2;
	temp2->next = temp;
}

//Get the element in the next helper
template <typename T> T POINTER_LIST<T>::RETRIEVE(helper<T>* position)
{
	return position->next->element;
}

//Get pointer to the helper that points to the helper with element 'x'
template <typename T> helper<T>* POINTER_LIST<T>::LOCATE(T x)
{
	helper<T>* cur = header;
	while(cur->next != nullptr)
	{
		if(cur->next->element == x)
			return cur;
		cur = cur->next;
	}
	return cur;
}

//Delete the helper pointed to by the helper that position points to
template <typename T> void POINTER_LIST<T>::DELETE(helper<T>* position)
{
	position->next = position->next->next;
}

//Get the pointer to the helper, that the helper that position points to, points
//to
template <typename T> helper<T>* POINTER_LIST<T>::NEXT(helper<T>* position)
{
	return position->next;
}

//Get the pointer to the helper that points at the helper pointed to by position
template <typename T> helper<T>* POINTER_LIST<T>::PREVIOUS(helper<T>* position)
{
	helper<T>* cur = header;
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
	helper<T>* temp = new helper<T>;
	temp->element = e;
	temp->next = nullptr;

	if(header->next == nullptr)
	{
		header->next = temp;
	}
	else
	{
		helper<T>* old_first_element = header->next;
		header->next = temp;
		temp->next = old_first_element;
	}
}

//Another debugging function. Please ignore for HW1
template <typename T> void POINTER_LIST<T>::print()
{
	helper<T>* cur = header->next;
	while(cur != nullptr)
	{
		std::cout << cur->element << std::endl;
		std::cout << cur->next << std::endl << std::endl;
		cur = cur->next;
	}
}
