#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
vector<int> a;

int main(){
  cin >> N >> M;

  // M의 개수만큼 0을 넣어줌
  for(int i = 0; i < N; i++)
    a.push_back(i < M ? 0 : 1);
  do {
      for (int i = 0; i < N; i++)
        if (a[i] == 0)
          cout << i + 1 << ' ';
      cout << "\n";
  } while (next_permutation(a.begin(), a.end()));
}