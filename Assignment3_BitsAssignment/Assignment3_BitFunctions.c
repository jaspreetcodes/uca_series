#include <stdio.h>

int bitAnd(int x, int y)
{
  return ~(~x | ~y);
}

int bitXor(int x, int y) 
{
  return ~(~x & ~y) & ~(x & y);
}

int main()
{
   return 0;
}
