#include <stdlib.h>

struct pair
{
  int x;
  int y;
};

int f1(int *a, int *b) __CPROVER_assigns(*a, b)
{
  struct pair *p = (struct pair *)malloc(sizeof(struct pair));
  b = &(p->y);
  *b = 5;
}

int main()
{
  int m = 4;
  int n = 3;
  f1(&m, &n);

  return 0;
}
