/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * ordered-list-item.h
 * Copyright (C) 2017 matt <matt@matt-P-6860FX>
 *
 * orderedlist2-cpp is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * orderedlist2-cpp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ORDERED_LIST_ITEM_H_
#define _ORDERED_LIST_ITEM_H_

struct OrderedListItem
{
	int internalInt = 0;
	OrderedListItem *Next = nullptr;
	~OrderedListItem()
	{
		if(Next != 0)
			delete Next;
	}
};


#endif // _ORDERED_LIST_ITEM_H_

