#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n,i;
  int number;
  scanf("%d",&n);
  int array[10000] = {0,};

  for(i=0; i < n; i++){
    scanf("%d",&number);
    if(0 < number <= 10000){
      array[number - 1]++;
    }
  }


  for(i = 0; i < 10000; i++){
    if(array[i] != 0){
      for(int j = 0; j < array[i]; j++){
        printf("%d\n",i+1);
      }
    }
  }

}