#ifndef LIST_OF_CHILDREN_TREE_H_
#define LIST_OF_CHILDREN_TREE_H_
#include <cstddef>
#include "helper.h"
#include <iostream>
#ifndef TREENODE_H_
#define TREENODE_H_

struct node
{
		int index;
};


#endif
#ifndef TREESTRUCT_H_
#define TREESTRUCT_H_

#include "pointerlist.h"

template <typename T>
struct tree_struct
{
		int maxsize = 100;
		T* labels;
		POINTER_LIST<node>* header;
		node root;
};

#endif


template <typename T> class TREE{
	public:

		tree_struct<T> CREATEi(int i, T, tree_struct<T>*);
		node PARENT(tree_struct<T>, node);
		node LEFTMOST_CHILD(tree_struct<T>, node);
		node RIGHT_SIBLING(tree_struct<T>, node);
};

#endif

template <typename T>
node LEFTMOST_CHILD(tree_struct<T> t, node n)
{
	return t.header[n.index].RETRIEVE(t.header[n.index].FIRST());
}

template <typename T>
node PARENT(tree_struct<T> t, node n)
{
	for(int i = 1; i < t.maxsize; i++)
	{
		POINTER_LIST<node>* cur_list = t.header[i];
		helper<node>* cur_cell = cur_list->FIRST();

		while(cur_cell != nullptr)
		{
			if(n.index == cur_cell->element.index)
			{
				return t.header[i];
			}
			cur_cell = cur_list->NEXT(cur_cell);
		}
	}

	node not_found;
	not_found.index = 0;
	return not_found;
}

template <typename T>
tree_struct<T> CREATEi(int i, T label, tree_struct<T>* trees)
{
	int new_maxsize = 0;

	tree_struct<T> new_tree;

	for(int j = 0; j < i; j++)
	{
		new_maxsize += trees[j].maxsize;
	}




	new_tree.maxsize = new_maxsize;
	new_tree.header = new POINTER_LIST<node>[new_maxsize];
	new_tree.labels = new T[new_maxsize];
	new_tree.labels[1] = label;


	node new_root_node;
	new_root_node.index = 1;
	new_tree.root = new_root_node;



	int counter_in_header_array = 2;
	int offset = 0;
	int label_index = 2;



	for(int k = 0; k < i; k++)
	{
		offset = counter_in_header_array - 1;

		node next_child_of_root;
		next_child_of_root.index = counter_in_header_array;

		new_tree.header[1].INSERT(next_child_of_root, new_tree.header[1].END());


		tree_struct<T> cur_tree = trees[k];
		int no_of_lists = cur_tree.maxsize;

		for(int l = 1; l < no_of_lists; l++)
		{
			POINTER_LIST<node> cur_list = cur_tree.header[l];
			helper<node>* cur_node = cur_list.NEXT(cur_list.FIRST());

			while(cur_node != nullptr)
			{
				node temp;
				temp.index = cur_node->element.index + offset;
				new_tree.header[counter_in_header_array].INSERT(temp, new_tree.header[counter_in_header_array].END());
				cur_node = cur_node->next;
			}

			counter_in_header_array++;

		}
		std::cout << counter_in_header_array << std::endl;
	}
	return new_tree;

}

template <typename T>
node RIGHT_SIBLING(tree_struct<T> t, node n)
{
	node parent = PARENT(t, n);
	POINTER_LIST<node> children = t.header[parent.index];
	helper<node>* cur_cell = children.FIRST();

	while(cur_cell != nullptr)
	{
		if(cur_cell->element.index == n.index)
			return cur_cell->next->element;
		cur_cell = children.NEXT(cur_cell);
	}

	node null;
	null.index = 0;
	return null;
}

template <typename T>
T LABEL(tree_struct<T> t, node n)
{
	return t.labels[n.index];
}

template <typename T>
node ROOT(tree_struct<T> t)
{
	return t.root;
}

template <typename T>
void MAKENULL(tree_struct<T> t)
{
	int maxsize = t.maxsize;
	t.root = 0;
	t.header = new POINTER_LIST<T>[maxsize];
	t.labels = new T[maxsize];
}

template <typename T>
void PRINT_TREE(tree_struct<T> t)
{

}
