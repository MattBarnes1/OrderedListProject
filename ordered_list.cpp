// $NAME <$ID@uakron.edu>
//
// Ordered_list.hpp: Implementation of the Ordered_list class

#include "ordered_list.hpp"

#include <iostream>

int Ordered_list::count()
{
	return listCount;
}


bool Ordered_list::insert(int anInt, OrderedListItem* previousItem, OrderedListItem* currentItem)
{
	if(currentItem->internalInt == anInt)
	{
		return false;
	}
	else if(anInt < currentItem->internalInt)
	{
		if(previousItem == 0) //only true if it's the first element in the list
		{
			OrderedListItem *newItem = new OrderedListItem();
			newItem->internalInt = anInt;
			newItem->Next = currentItem;
			orderedList = newItem;
			listCount++;

		} else {
			OrderedListItem *newItem = new OrderedListItem();
			newItem->internalInt = anInt;
			previousItem->Next = newItem;
			newItem->Next = currentItem;
			listCount++;
		}
		return true;
	}
	else if(anInt > currentItem->internalInt)
	{
		if(currentItem->Next != 0)
		{
			return insert(anInt, currentItem, currentItem->Next);
        } else {
			OrderedListItem *newItem = new OrderedListItem();
			newItem->internalInt = anInt;
			currentItem->Next = newItem;
			listCount++;
			return true;
		}
	}	
}

bool Ordered_list::search(int anInt, OrderedListItem* anItem)
{
	if(orderedList == 0)
	{
		return false;
	}
	
	if(anItem->internalInt == anInt)
	{
		return true;
	}
	else if (anItem->Next != 0)
	{
		return search(anInt, anItem->Next);
	} else {
		return false;
	}
}

bool Ordered_list::remove(int anInt, OrderedListItem* previousItem, OrderedListItem* currentItem)
{
	if(currentItem->internalInt == anInt)
	{
		if(previousItem == 0)
		{
			if(currentItem->Next != 0)
			{
				orderedList = currentItem->Next;
				currentItem->Next = 0;
				listCount--;
				delete currentItem;
				return true;
			} else {
				listCount = 0;
				delete orderedList;
				orderedList = 0;
				return true;
			}
		} else {
			previousItem->Next = currentItem->Next;
			currentItem->Next = 0; //So we don't delete everything after currentItem;
			delete currentItem;
			listCount--;
			return true;
		}
	} 
	else if(currentItem->internalInt < anInt)
	{
		if(currentItem->Next != 0)
		{
			return remove(anInt, currentItem, currentItem->Next);
		} else {
			return false;
		}
	}
	else if(currentItem->internalInt > anInt)
	{
		return false;
	}
}


bool Ordered_list::insert(int anInt)
{
	if(orderedList == 0)
	{
		orderedList = new OrderedListItem();
		orderedList->internalInt = anInt;
		listCount++;
		return true;
	}
	
	return insert(anInt, 0, orderedList);
}

bool Ordered_list::search(int anInt)
{
	if(orderedList == 0)
	{
		return false;
	}
	return search(anInt, orderedList);
}

bool Ordered_list::remove(int anInt)
{
	if(orderedList == 0)
	{
		return false;
	}
	
	return remove(anInt, 0, orderedList);
}

Ordered_list::Ordered_list()
{
	
}

Ordered_list::~Ordered_list()
{
	if(orderedList != 0)
	{
		delete orderedList;
	}
}

void Ordered_list::clear()
{
	if(orderedList != 0)
	{
		delete orderedList;
		orderedList = 0;
		listCount = 0;
	}
}

void Ordered_list::display(OrderedListItem *myListItemToDisplay)
{
		if(listCount != 0)
		{
			std::cout << "[" << myListItemToDisplay->internalInt << "]";
			if(myListItemToDisplay->Next != 0)
			{
				display(myListItemToDisplay->Next);
			}
		}
}

void Ordered_list::display()
{
	if(orderedList != 0)
	{
		display(orderedList);
	}
	std::cout << std::endl;
}

bool Ordered_list::is_empty()
{
	return (listCount == 0);
}
