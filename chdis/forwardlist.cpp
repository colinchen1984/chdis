//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//


#include <stdlib.h>
#include "forwardlist.h"

forwardlist::node* createflnode()
{
	auto n = (forwardlist::node*)malloc(sizeof(forwardlist::node));
	n->data = nullptr;
	n->next = nullptr;
	return n;
}

void destoryflnode(forwardlist::node* n)
{
	free(n);
}

//craete a list
forwardlist* createforwadlist()
{
	auto fl = (forwardlist*)malloc(sizeof(forwardlist));
	fl->tail = fl->head = nullptr;
	fl->count = 0;
	return fl;
}

//destory a list
void destoryflist(forwardlist * l)
{
	while(lflpop(l) != nullptr)
	{

	}
	free(l);
}

void rflistpush(forwardlist *l, void *d)
{
	auto n = createflnode();
	n->data = d;
	do
	{
		if(0 == l->count)
		{
			l->tail = l->head = n;
		}
		l->tail->next = n;
		l->tail = n;
		n->next = nullptr;
		++l->count;
	}while(false);
}

void lflistpush(forwardlist *l, void *d)
{
	auto n = createflnode();
	n->data = d;
	do
	{
		if(0 == l->count)
		{
			l->tail = n;
		}
		n->next = l->head;
		l->head = n;
		++l->count;
	}while(false);
}

//pop data from head
void* lflpop(forwardlist * l)
{
	void* r = nullptr;
	do
	{
		if(0 == l->count)
		{
			break;
		}

		auto n = l->head;
		r = n->data;
		l->head = n->next;
		--l->count;
		if(0 == l->count)
		{
			l->tail = nullptr;
		}
		destoryflnode(n);
	}while(false);
	return r;
}

void*removeflnode(forwardlist *l, fliterator *i)
{
	void* ret = nullptr;
	do
	{
		if(l != i->l || 0 == l->count)
		{
			break;
		}

		if(nullptr == i->currentnode)
		{
			break;
		}
		auto n = i->currentnode;
		auto prev = l->head;
		while(prev->next != n)
		{
			prev = prev->next;
		}
		if(prev->next != n)
		{
			break;
		}
		prev->next = n->next;
		ret = n->data;
		destoryflnode(n);
	}while(false);
	return ret;
}

//create a iterator for list
fliterator createfliterator(forwardlist * l)
{
	fliterator i;
	i.l = l;
	i.currentnode = l->head;
	return i;
}

//get data from iterator
void* getflistdata(fliterator* i)
{
	void* ret = nullptr;
	if(nullptr != i->currentnode)
	{
		ret = i->currentnode->data;
	}
	return ret;
}

//move on
void flireatornext(fliterator* i)
{
	if(nullptr != i->currentnode)
	{
		i->currentnode = i->currentnode->next;
	}
}


