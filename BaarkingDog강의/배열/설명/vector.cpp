#include<bits/stdc++.h>
using namespace std;

int main(void){
  vector<int> v1(3,5); // {5, 5, 5};
  cout << v1.size() << "\n"; // 3
  v1.push_back(7); // {5,5,5,7}

  vector<int> v2(2); // {0, 0}
  v2.insert(v2.begin() + 1, 3); // {0, 3, 0}
  cout << v2[0] << v2[1] << v2[2] << "\n";

  vector<int> v3 = {1,2,3,4};
  v3.erase(v3.begin() + 2); // {1,2,4}

  vector<int> v4;
  v4 = v3; // {1,2,4}
  cout << v4[0] << v4[1] << v4[2] << "\n"; 
  v4.pop_back(); // {1,2}
  v4.clear(); // {}



  // 배열의 인덱스에 접근해 값을 출력하는 방법
  vector<int> v1 = {1,2,3,4,5,6};

  // 1. range-based for loop
  for(int e : v1) // 복사된 값이 e에 들어감 -> e를 바꿔도 v1에는 영향 x
    cout << e << " ";

  for(int& e : v1) // 원본이 e에 들어감 -> e를 바꾸면  v1에 영향 O
    cout << e << " ";
  
  // 2. not bad
  for(int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";

  // 3. wrong!!
  for(int i = 0; i <= v1.size() - 1; i++)
    cout << v1[i] << " ";
  /*
  vector의 size()메소드는 unsigned int를 반환한다.
  따라서 3번 같이 쓰면 v1이 빈 vector일 때 unsigned int 0에서 int 1을 빼는
  식이 되고, unsigned int와 int를 연산하면 unsigned int로 자동 형변환이
  발생하기 때문에 (unsigned int)0 - (int)1은 -1이 아니라 4294967295가 되어버린다. unsigned int overflow로 인해 생긴 값이다. 그래서 아무것도 출력이 안되는게 아니라 v[0], v[1] ,... 쭉 가다가 런타임에러가 발생할 것이다.
  */

}