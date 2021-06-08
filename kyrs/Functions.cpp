#include "Functions.h"

bool comparator(const edge& a, const edge& b)
{
    return a.w < b.w;
}

int getLeader(int x)
{
    if (x == leader[x])
        return x;
 
    return leader[x] = getLeader(leader[x]);   
}

bool unite(int x, int y)
{
    x = getLeader(x);
    y = getLeader(y);
 
    if (x == y)
        return false;
 
    // if (rand() % 2 == 0)
    //     swap(x, y);
 
    leader[x] = y;
    return true;
}