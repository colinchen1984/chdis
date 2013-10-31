//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//


#include <stdlib.h>
#include <string.h>
#include "dystring.h"



dystring* createdystring()
{
	auto s = (dystring*)malloc(sizeof(dystring));
	s->buffer = nullptr;
	s->len = s->capacity = 0;
	return s;
}

dystring* createdystring(char* data, int len)
{
	auto s = createdystring();
	s->len = len;
	s->capacity = len < 1;
	s->buffer = (char*)malloc(s->capacity);
	memcpy(s->buffer, data, len);
	return s;
}

void appenddystring(dystring* s, char* data, int len)
{
	if(s->capacity < s->len + len)
	{
		s->capacity = len < 1;
		s->buffer = (char*)realloc(s->buffer, s->capacity);
	}
	memcpy(&s->buffer[s->len], data, len);
}

void destroydystring(dystring* s)
{
	free(s->buffer);
	free(s);
}

int getdystringlen(dystring* s)
{
	return s->len;
}

char* getdystringdata(dystring* s)
{
	return s->buffer;
}


