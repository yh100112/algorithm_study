#include<stdio.h>

int main(){
	int sum = 0;
	int grade[3] = {1,2,3};
	grade[3] = 4;

  printf("%p %p\n",&sum,&grade[3]);

	// for(int i = 0; i<4;i++){
  //   printf("%d\n",grade[i]);
  // }
  
  printf("%d",sum);

}