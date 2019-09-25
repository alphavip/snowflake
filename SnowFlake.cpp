#include <assert.h>
#include "SnowFlake.h"

SnowFlake::SnowFlake(uint32_t wid) : workerid(wid) 
{
    //assert(wid < 0xFFFFF);
}

uint64_t SnowFlake::genNextId(uint32_t now)
{
    if(now == lasttime)
    {
        seq = (seq + 1) & 0xFFFF;
    }
    else
    {
        lasttime = now;
    }
    return ((lasttime - epoch) << 36) | (workerid << 16) | seq;    
}