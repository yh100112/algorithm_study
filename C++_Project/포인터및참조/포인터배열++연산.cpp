#include<stdio.h>
#include<string.h>

typedef struct hello{
  int checkNum;
}hello;

hello headers[10];
int main(){
  hello *h = headers;
  h[0].checkNum = 0;
  h[1].checkNum = 1;
  h[2].checkNum = 2;

  printf("%d\n",h->checkNum); // 0
  h++;
  printf("%d\n",h->checkNum); // 1

}