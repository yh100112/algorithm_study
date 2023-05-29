#include<iostream>
using namespace std;

int N,arr[1000001];
int* arr2;

void merge(int left, int right){
  int mid = (left + right) / 2;

  int i = left;
  int j = mid + 1;
  int k = left;

  //두 개의 분할된 배열의 값들을 서로 비교하며 새로운 배열에 정렬해서 넣음
  while(i <= mid && j <= right){
    if(arr[i] <= arr[j]){
      arr2[k++] = arr[i++];
    }else{
      arr2[k++] = arr[j++];
    }
  }

  //값이 남은 배열을 찾아서 남은 값들을 새로운 배열의 뒷부분에 순서대로 넣음
  int tmp = i > mid ? j : i;
  while(k <= right){
    arr2[k++] = arr[tmp++];
  }

  //임시 배열인 arr2의 값들을 실제 배열에 복사해줌
  for(int i = left; i <= right; i++){
    arr[i] = arr2[i];
  }
}

void partition(int left, int right){
  int mid;
  if(left < right){
    mid = (left + right) / 2;
    partition(left,mid);
    partition(mid + 1, right);
    merge(left, right);
  }
}

int main(){
  scanf("%d",&N);
  arr2 = new int[N];
  for(int i = 0; i < N; i++){
    scanf("%d",&arr[i]);
  }

  partition(0,N-1);

  for(int i = 0; i < N; i++){
    printf("%d\n",arr[i]);
  }
}