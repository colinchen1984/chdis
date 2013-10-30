//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//



#ifndef __forwardlist_H_
#define __forwardlist_H_


struct forwardlist {
	struct node
	{
		void* data;
		node* next;
	};
	node* head;
	node* tail;
	int count;
};

struct fliterator
{
	forwardlist * l;
	forwardlist::node* currentnode;

};

//craete a list
forwardlist * createforwadlist();

//destory a list
void destoryflist(forwardlist * l);

//push a data to list at tail
void rflistpush(forwardlist *l, void *d);

//push a data to list at head
void lflistpush(forwardlist *l, void *d);

//pop data from head
void* lflpop(forwardlist * l);

//delete a node in list
void*removeflnode(forwardlist *l, fliterator *i);

//create a iterator for list
fliterator createfliterator(forwardlist * l);

//get data from iterator
void* getflistdata(fliterator* i);

//move on
void flireatornext(fliterator* i);

#endif //__forwardlist_H_
