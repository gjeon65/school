#ifndef POINTER_LIST_H_
#define POINTER_LIST_H_
#include <cstddef>
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

#endif 

template <typename T> POINTER_LIST<T>::POINTER_LIST()
{
	header = new helper<T>;
	header->next = NULL;
}

template <typename T> helper<T>* POINTER_LIST<T>::FIRST()
{
	return header;
}

template <typename T> helper<T>* POINTER_LIST<T>::END()
{
	helper<T>* cur = header;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}
template <typename T> void POINTER_LIST<T>::INSERT(T e, helper<T>* position)
{
	helper<T>* temp = position->next;

	helper<T>* temp2 = new helper<T>;
	temp2->element = e;

	position->next=temp2;
	temp2->next = temp;
}

template <typename T> T POINTER_LIST<T>::RETRIEVE(helper<T>* position)
{
	return position->next->element;
}

template <typename T> helper<T>* POINTER_LIST<T>::LOCATE(T x)
{
	helper<T>* cur = header;
	while(cur->next != NULL)
	{
		if(cur->next->element == x)
			return cur;
		cur = cur->next;
	}
	return cur;
}
template <typename T> void POINTER_LIST<T>::DELETE(helper<T>* position)
{
	position->next = position->next->next;
}

template <typename T> helper<T>* POINTER_LIST<T>::NEXT(helper<T>* position)
{
	return position->next;
}

template <typename T> helper<T>* POINTER_LIST<T>::PREVIOUS(helper<T>* position)
{
	helper<T>* cur = header;
	while(cur->next != position)
	{
		cur = cur->next;
	}
	return cur;
}
template <typename T> void POINTER_LIST<T>::MAKENULL()
{
	header->next = NULL;
}
template <typename T> void POINTER_LIST<T>::append_beginning(T e)
{
	helper<T>* temp = new helper<T>;
	temp->element = e;
	temp->next = NULL;

	if(header->next == NULL)
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

template <typename T> void POINTER_LIST<T>::print()
{
	helper<T>* cur = header->next;
	while(cur != NULL)
	{
		std::cout << cur->element << std::endl;
		std::cout << cur->next << std::endl << std::endl;
		cur = cur->next;
	}
}
