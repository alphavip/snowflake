#ifndef _SNOWFLAKE_H_
#define _SNOWFLAKE_H_
#include <stdint.h>

//bit63-bit35时间戳(秒级) |bit16-bit35 0xFFFFF workerid |bit0-bit15序列号0xFFFF
//时间戳支持到2036年会进行循环，序列号支持一秒内生成65535个
//这样的分配bit位可能不适合你



struct SnowFlake
{
	SnowFlake(uint32_t wid);
	virtual ~SnowFlake() {}

	uint64_t genNextId(uint32_t now);

	uint32_t workerid;
	uint32_t seq;
	uint32_t lasttime;//in second
	const static uint32_t epoch = 1569415623;
};


#endif //_SNOWFLAKE_H_