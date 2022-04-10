#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> um;

int main(){
  um[3]++;            //map과 마찬가지로 그냥 um[] 이렇게만 하면 알아서 키와 쌍을 이루는 value를 넣어줌 (int이므로 0을 넣어줌)
  printf("%d\n",um[3]); // 1
}