#include <stdio.h>

int bitAnd(int x, int y)
{
  return ~(~x | ~y);
}

int bitXor(int x, int y) 
{
  return ~(~x & ~y) & ~(x & y);
}

int sign(int x) 
{
  return ((!!x) | (x >> 31));
}

int getByte(int x, int n) 
{
  return (x >> (n << 3)) & 0xff;
}

int logicalShift(int x, int n) 
{
  return (x >> n) & (~(((1 << 31) >> n) << 1));
}

int conditional(int x, int y, int z) 
{
  return z ^ ((y ^ z) & ((!x) + ~0));
}

int bang(int x)
{
  return (((~x + 1) | x) >> 31) + 1;
}

int invert( int x, int p, int n)
{
    int num = 1357;
    int N, n1, p = 2, n = 6;
    n1 = 1 << (n);
    N = (~n1)^(1<<(n+1));
    N = N << p;
    return N;
}

int main()
{
   return 0;
}
