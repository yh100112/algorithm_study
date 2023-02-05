#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

// c++은 split()함수가 없으므로 문자열을 나눌 때 직접 만들어서 사용
void split(string time, vector<int>& v) {
  stringstream ss;
  string word;
  ss.str(time);
  while(getline(ss, word, ':')){
    v.emplace_back(stoi(word));
  }
}

int main(){
  string start, end;
  vector<int> t1;
  vector<int> t2;
  int result = 0;
  for(int i = 0; i < 5; i++) {
    cin >> start >> end;
    
    split(start, t1);
    split(end, t2);

    if(t2[1] > t1[1])
      result += t2[1] - t1[1] + (t2[0] - t1[0]) * 60;
    else
      result += 60 - t1[1] + t2[1] + (t2[0] - (t1[0] + 1)) * 60;
	t1.clear();
	t2.clear();
  }
  cout << result;
}