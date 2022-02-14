#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
  string a = "hello1234";
  int c;
  for(int i = 0; i < a.length(); i++){
    if(a[i] >= '0' && a[i] <= '9'){
      printf("%c\n",a[i]);
    }
  }

}