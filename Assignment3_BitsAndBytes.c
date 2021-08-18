
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}

int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}
