#include <stdio.h>

template <typename T>
void Swap(T &a, T &b){
  T t;
  t = a;
  a = b;
  b = t;
}

struct tag_st
{  
  int i;
  double d;
};

void main(){
  int a = 3, b = 4;
  double c = 1.2, d = 3.4;
  char e = 'e', f = 'f';
  tag_st g = {1, 2.3}, h = {4, 5.6};

  Swap(a, b);
  
  Swap(c, d);

  Swap(e, f);

  Swap(g, h);
}