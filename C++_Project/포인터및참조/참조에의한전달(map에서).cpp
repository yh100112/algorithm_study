#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string.h>
using namespace std;


struct Test{
  int a;
  int b;
  Test():a(0),b(0){}
  ~Test(){}
};


int main(){
  map<int,struct Test> m;

  int cnt = 1;
  while(1){
    if(cnt == 3) break;
    char input[10];
    printf("입력 : ");
    scanf("%s",input);

    if(strcmp(input,"true") == 0){
      m[1];
    }else{
      struct Test& tt = m[1]; // m[1] 그 자체를 가져옴 ( 참조에 의한 전달 )
      //이렇게 하면 그냥 struct Test tt로 선언했을 때는 아예 새로운 구조체를 선언해서 거기에 값의 복사본을 넣었을 뿐이라서
      //원본에 영향이 가지 않는데, struct Test&를 하면 원본 그 자체를 가져온 것이므로 원본에 영향이 간다.
      tt.a = 3;
      tt.b = 5;
    }
    cnt++;
  } 
  for(pair<int,struct Test> atom : m){
    printf("key : %d  / value a,b : %d %d\n",atom.first,atom.second.a,atom.second.b);
  }


}