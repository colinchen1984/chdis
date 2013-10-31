//
//  main.cpp
//  chdis
//
//  Created by ChenLin on 13-10-30.
//  Copyright (c) 2013 GYGame. All rights reserved.
//

#include <iostream>
#include "list.h"
#include "forwardlist.h"

int main(int argc, const char * argv[])
{

	// insert code here...
	auto l = createforwadlist();
	lflistpush(l, (void *) 1321);
	lflistpush(l, (void *) 344);
	rflistpush(l, (void *) 34);
	auto i = createfliterator(l);
	flireatornext(&i);
	removeflnode(l, &i);
	i = createfliterator(l);
	while(auto d = getflistdata(&i))
	{
		std::cout << (int64_t)d;
		flireatornext(&i);
	}
	std::cout.flush();
	destoryflist(l);
	return 0;
}


