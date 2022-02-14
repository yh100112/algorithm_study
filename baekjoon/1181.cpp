
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
  if(a.length() < b.length()){
    return 1;
  }else if(a.length() > b.length()){
    return 0;
  }else{
    return a < b; 
  }
  
}

int main(){
  int n,i,j;
  string word[20000];

  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    cin >> word[i];
  }

  sort(word,word + n,compare);

  for(int i = 0; i < n; i++){
    if(i > 0 && word[i] == word[i - 1]){
      continue;
    }else{
      cout << word[i] << endl;
    }
  }

}