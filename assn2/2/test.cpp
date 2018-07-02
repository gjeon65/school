#include <iostream>
#include "listOfChildren.h"

using namespace std;

int main()
{

	tree_struct<int>* t = new tree_struct<int>[5];

	for (int i = 0; i < 4; i++)
	{
		t[i].maxsize = 5;
		t[i].header = new POINTER_LIST<node>[t[i].maxsize];
		node first_child;
		node second_child;
		first_child.index = 3;
		second_child.index = 4;

		t[i].header[1].INSERT(first_child, t[i].header[1].END());
		t[i].header[1].INSERT(second_child, t[i].header[1].END());
		t[i].labels = new int[t[i].maxsize];
		node root;
		root.index = 1;
		t[i].root = root;


	}
	tree_struct<int> new_t = CREATEi<int>(3,3,t);
}


