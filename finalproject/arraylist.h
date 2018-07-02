/*
Geun Jeon
CS260
Assingment1
2-18-2018
*/

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_
#include <iostream>
using namespace std;

template< typename T >
class LIST{
private:
	T *array;
	int _maxsize;
	int _last;
public:
	LIST();
	LIST(int);
	int FIRST();
	int END();
	T RETRIEVE(int);
	int LOCATE(T);
	int NEXT(int);
	int PREVIOUS(int);
	void INSERT(T, int);
	void DELETE(int);
	void MAKENULL();
	void print();
};

#endif 

template< typename T >
LIST<T>::LIST(int maxsize)
{
	_last = 0;	
	_maxsize = maxsize;
	array = new T[_maxsize];
}

template< typename T >
LIST<T>::LIST()
{
	_last = 0;	
	_maxsize = 100;
	array = new T[_maxsize];
}

template< typename T >
int LIST<T>::FIRST()
{
	if(_last == 0)
		return END();
	else
		return 1;
}

template< typename T >
int LIST<T>::END()
{
	return _last + 1;
}

template< typename T >
T LIST<T>::RETRIEVE(int pos)
{
	return array[pos - 1];
}

template< typename T >
int LIST<T>::LOCATE(T element)
{
	for(int i = 0; i < _last; i++)
	{
		if(array[i] == element)
			return i + 1;
	}
	return END();
}

template< typename T >
int LIST<T>::NEXT(int pos)
{
	return pos + 1;
}

template< typename T >
int LIST<T>::PREVIOUS(int pos)
{

	return pos - 1;
}

template< typename T >
void LIST<T>::INSERT(T element, int pos)
{
	if(pos < FIRST() || pos > END())
		cout << "Invalid position" << endl;
	else if(_last + 1 > _maxsize)
		cout << "No space" << endl;
	else
	{
		int actual_index = pos - 1;
		for(int i = _last - 1; i >= actual_index ; i--)
		{
			array[i + 1] = array[i];
		}
		array[actual_index] = element;
		_last++;
	}
}

template< typename T >
void LIST<T>::DELETE(int pos)
{
	if(pos < FIRST() || pos > END())
		cout << "Invalid position" << endl;
	else
	{
		int actual_index = pos - 1;
		for(int i = actual_index; i < _last ; i++)
		{
			array[i] = array[i + 1];
		}
		_last--;
	}
}

template< typename T >
void LIST<T>::MAKENULL()
{
	_last = 0;	
	
}

template <typename T>
void LIST<T>::print()
{
	for(int i = 0; i < _last; i++)
	{
		cout << i + 1 << ":" << array[i] << endl;
	}
}
