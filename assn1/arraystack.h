/*
Geun Jeon
CS260
Assignment1
2-18-2018
*/

#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_
#include <iostream>
using namespace std;

template< typename T > class STACK{
private:
	T *array;
	int _maxsize;
	int _top;
public:
	STACK();
	STACK(int);
	T TOP();
	void POP();
	void PUSH(T);
	bool EMPTY();
	void MAKENULL();
	void print();
};

#endif 

template< typename T >
STACK<T>::STACK(int maxsize)
{
	_top = 0;	
	_maxsize = maxsize;
	array = new T[_maxsize];
}

template< typename T >
STACK<T>::STACK()
{
	_top = 0;	 
	_maxsize = 100;
	array = new T[_maxsize];
}

template<typename T>
T STACK<T>::TOP()
{
	if(_top != 0)
		return array[_top - 1];
}

template<typename T>
void STACK<T>::POP()
{
	if(_top != 0)
		_top--;
}

template<typename T>
void STACK<T>::PUSH(T x)
{
	array[_top] = x;
	_top++;
}

template<typename T>
bool STACK<T>::EMPTY()
{
	if(_top == 0)
		return true;
	else
		return false;
}

template<typename T>
void STACK<T>::MAKENULL()
{
	_top = 0;
}

template<typename T>
void STACK<T>::print()
{
	for(int i = _top - 1; i >= 0; i--)
	{
		cout << array[i] << endl;
	}
}
