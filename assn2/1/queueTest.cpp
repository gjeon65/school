#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
	cout<<"Test for queue\n";
	Queue<string> Q;
	
	cout<<"Testing front, queue = 45"<<endl;
	Q.Enqueue("3");	
	cout<<"Queue front: "<<Q.Front()<<". Returning 3"<<endl;
	//adding queues for the later tests.
	Q.Enqueue("7");
	cout<<"Testing empty()"<< Q.Empty()<<". Returning 0."<<endl;
	Q.Dequeue();
	cout<<"Testing dequeue\n"<< Q.Front() <<"returning 7"<<endl;
	Q.Dequeue();
	cout <<"Testing empty() "<< Q.Empty() <<"returing 1"<<endl;
	Q.MakeNull();
	cout<<"Testing makenull, result: " <<Q.Empty() <<endl; 
	return 0;
}
