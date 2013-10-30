//
// Created by ChenLin on 13-10-30.
// Copyright (c) 2013 GYGame. All rights reserved.
//



#ifndef __dystring_H_
#define __dystring_H_


struct dystring {
	char* buffer = nullptr;
	int len = 0;
	int capacity = 0;
};

//create dystring
dystring* createdystring();

//create dystring with c-string
dystring* createddystring(char* data, int len);

//append c-string to dystring
void appenddystring(dystring* string, char* data, int len);

//destroy dystring
void destroydystring(dystring* dystring);

//get length of data
int getdystringlen(dystring* string);

//get data
char* getdystringdata(dystring* string);

#endif //__dystring_H_
