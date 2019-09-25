#include <time.h>
#include <iostream>
#include "SnowFlake.h"

int main()
{
	SnowFlake sf(10002);
	for(uint32_t i = 0; i < 1000; ++i)
		std::cout << sf.genNextId(time(NULL)) << std::endl;

	return 0;
}