//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//



#ifndef __list_H_
#define __list_H_

#include "define.h"

class list {
public:
	struct node
	{
		node* prev;
		node* next;
		void* data;
	};

	node* head;
	node* tail;
	int32_t count;

};

struct literator
{
	list * l;
	list::node* currentnode;

};

//craete a list
list * createlist();

//destory a list
void destorylist(list * l);

//push a dystring to list at tail
void rlistpush(list *l, void *d);

//push a dystring to list at head
void llistpush(list *l, void *d);

//pop data from head
void* lpop(list * l);

//pop data from tail
void* rpop(list * l);

//delete a node in list
void* removelnode(list *l, literator *i);

//create a iterator for list
literator createliterator(list * l);

//create a revert iterator for list
literator rcreateliterator(list * l);

//get data from iterator
void* getlistdata(literator* i);

//move on
void ireatornext(literator* i);

//move prev
void ireatorprev(literator* i);
#endif //__list_H_

