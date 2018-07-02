/*
Geun Jeon
CS260
Assn2
Queue
*/
#include <iostream>

using namespace std;
template<typename E>
class Node{
	public:
		Node();
		E element;
		Node* next;
};

template<typename E>
Node<E>::Node(){
}

template<typename E>
class Queue{
	private:
		Node<E> *front;
		Node<E> *rear;
	public:
		Queue();
		E Front();
		void Enqueue(E x);
		void Dequeue();
		bool Empty();
		void MakeNull();
};
template<typename E>
Queue<E>::Queue(){
	front = new Node<E>();
	rear = front; 
}
template<typename E>
E Queue<E>::Front(){
	if (Empty()){
		cout<< "Empty queue"<< endl;
	}
	else{
		return front->next->element;
	}
}

template<typename E>
void Queue<E>::Enqueue(E x){
	Node<E> *tmp = new Node<E>();
	tmp->element = x;
	tmp->next = NULL;
	rear->next = tmp;
	rear = tmp;
}

template<typename E>
void Queue<E>::Dequeue(){
	if (!Empty()){
		front  = front->next;
	}
}

template<typename E>
bool Queue<E>::Empty(){
		return front == rear;
}

template<typename E>
void Queue<E>::MakeNull(){
	while(!Empty()){
		Dequeue();
	}
};
