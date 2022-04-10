#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


/*포인터 매개변수*/
// void setToNull(int*);

// int main(){
//   int five = 5;
//   int* ptr = &five;

//   printf("&ptr:%p | ptr: %p\n",&ptr,ptr);

//   setToNull(ptr); 

//   if(ptr != nullptr)
//     cout <<*ptr << endl;
//   else
//     cout << "ptr is null";
  

//   return 0;
// }

// void setToNull(int* tempPtr){
//   printf("tempPtr:%p | &tempPtr :%p | *tempPtr : %p\n",tempPtr,&tempPtr,*tempPtr);
//   tempPtr = nullptr;
// }

/*이중포인터*/
void setToNull(int**);

int main(){
  int five = 5;
  int* ptr = &five;

  printf("&ptr:%p | ptr(변수 five의 주소값 ): %p\n",&ptr,ptr); // ptr포인터변수의 주소값과 ptr포인터변수 안에 들어있는 주소값은 다르다.
  setToNull(&ptr); 

  if(ptr != nullptr){ 
    cout <<*ptr << endl;
  } else{
    cout << "ptr is null";
  }

  return 0;
}

void setToNull(int** tempPtr){
  printf("tempPtr:%p | &tempPtr:%p | *tempPtr :%p\n",tempPtr,&tempPtr,*tempPtr);
  *tempPtr = nullptr;
}
