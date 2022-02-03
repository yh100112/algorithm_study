#include<iostream>
#include<string>
#include<unordered_map> 
using namespace std;

int main(){

  unordered_map<string,int> um;

  if(um.empty()){
    printf("unordered_map은 비어있다.\n");
  }

  um.insert(make_pair("key",1));
  um["banana"] = 2;
  um.insert({"melon",3});

  printf("unordered_map의 크기 : %d\n",um.size());

  for(auto elem : um){
    cout << "key : " << elem.first << " value : " << elem.second << endl;
  }

  printf("%d\n",um.find("banana")->second);
  printf("%d\n",um.begin()->second);
}