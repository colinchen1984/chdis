//
//  main.cpp
//  chdis
//
//  Created by ChenLin on 13-10-30.
//  Copyright (c) 2013 GYGame. All rights reserved.
//

#include <iostream>
#include "list.h"
int main(int argc, const char * argv[])
{

	// insert code here...
	auto l = createlist();
	rlistpush(l, (void *) 1321);
	rlistpush(l, (void *) 344);
	llistpush(l, (void *) 34);
	auto i = createliterator(l);
	while(auto d = getlistdata(&i))
	{
		std::cout << (int64_t)d << "\t";
		ireatornext(&i);
	}
	std::cout.flush();
	destorylist(l);
	return 0;
}
