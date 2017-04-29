// $NAME <$ID@uakron.edu>
//
// Ordered_list.hpp: Definition of the Ordered_list class

#ifndef ORDERED_LIST_HPP
#define ORDERED_LIST_HPP

#include "ordered-list-item.h"
#include "stdlib.h"

class Ordered_list
{
public:
	bool  insert(int);
	bool search(int);
	bool  remove(int);
	Ordered_list();
	~Ordered_list();
	bool is_empty();
	void clear();
	void display();
	int count();
private:
	OrderedListItem *orderedList = 0;
	bool  insert(int, OrderedListItem*,  OrderedListItem*);
	bool search(int, OrderedListItem*);
	bool  remove(int, OrderedListItem*,  OrderedListItem*);
	void display(OrderedListItem*);
	size_t listCount = 0;
};

#endif
