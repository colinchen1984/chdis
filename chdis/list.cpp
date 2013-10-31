//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//


#include <stdlib.h>
#include "list.h"


list::node* createnode()
{
	auto n = (list::node*)malloc(sizeof(list::node));
	n->next = n->prev = nullptr;
	n->data = nullptr;
	return n;
}

void destorynode(list::node* n)
{
	free(n);
}

list * createlist()
{
	auto l = (list *)malloc(sizeof(list));
	l->count = 0;
	l->head = nullptr;
	l->tail = nullptr;
	return l;
}

void destorylist(list * l)
{
	while(nullptr != lpop(l))
	{
		;
	}
	free(l);
}

void rlistpush(list *l, void *s)
{
	auto n = createnode();
	n->data = s;
	do
	{

		if(nullptr == l->head)
		{
			l->head = n;
			l->tail = n;
			l->count = 1;
			break;
		}

		n->prev = l->tail;
		l->tail->next = n;
		l->tail = n;
		++l->count;
	}while(false);
}

void llistpush(list *l, void *s)
{
	auto n = createnode();
	n->data = s;
	do
	{

		if(nullptr == l->head)
		{
			l->head = n;
			l->tail = n;
			l->count = 1;
			break;
		}

		n->next = l->head;
		l->head->prev = n;
		l->head = n;
		++l->count;
	}while(false);
}

//pop data from head
void* lpop(list * l)
{
	void* r = nullptr;
	do
	{
		if(0 == l->count)
		{
			break;
		}

		r = l->tail->data;
		auto t = l->tail->prev;
		destorynode(l->tail);
		l->tail = t;
		--l->count;
		if(0 == l->count)
		{
			l->head = nullptr;
		}
	}while(false);
	return r;
}

//pop data from tail
void* rpop(list * l)
{
	void* r = nullptr;
	do
	{
		if(0 == l->count)
		{
			break;
		}

		r = l->head->data;
		auto t = l->head->next;
		destorynode(l->head);
		l->head = t;
		--l->count;
		if(0 == l->count)
		{
			l->tail = nullptr;
		}
	}while(false);
	return r;
}

//delete a node in list
void* removelnode(list *l, literator *i)
{
	void* ret = nullptr;
	do
	{
		if(i->l != l || 0 == l->count)
		{
			break;
		}

		if(i->currentnode == l->tail)
		{
			ret = rpop(l);
			break;
		}

		if(i->currentnode == l->head)
		{
			ret = lpop(l);
			break;
		}

		auto n = i->currentnode;
		n->prev->next = n->next;
		n->next->prev = n->prev;
		ret = n->data;
		destorynode(n);

	}while(false);
	return ret;
}

literator createliterator(list * l)
{
	literator i;
	i.currentnode = l->head;
	return i;
}

//create a revert iterator for list
literator rcreateliterator(list * l)
{
	auto i = createliterator(l);
	i.currentnode = l->tail;
	return i;
}

void* getlistdata(literator* i)
{
	void* r = nullptr;
	if(nullptr != i->currentnode)
	{
		r = i->currentnode->data;
	}
	return r;
}

void ireatornext(literator* i)
{
	if(nullptr != i->currentnode)
	{
		i->currentnode = i->currentnode->next;
	}
}

void ireatorprev(literator* i)
{
	if(nullptr != i->currentnode)
	{
		i->currentnode = i->currentnode->prev;
	}
}


