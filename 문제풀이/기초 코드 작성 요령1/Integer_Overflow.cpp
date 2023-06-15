#include<iostream>
using namespace std;

void func1(){
  for(char s = 0; s < 128; s++){
    cout << "hi" << endl;
  }
}

int func2(){
  int r = 1;
  for(int i = 1; i <= 50; i++){
    r = r * i % 61;
  }
  return r;
}

int func3(){
  int a = 10;
  int mod = 1000000007;
  for(int i = 0; i < 10; i++){
    a = 10 * a % mod;
    // cout << a << endl;
  }
  return a;
}

int main(){
  func3();
}

/*
integer overflow가 발생하는 경우는?
-> func1, func3

func1의 경우
-> s가 127이 된 후에 1이 더해질 때 -128이 되기 때문에 의도한대로 동작하지
  않고 무한루프에 빠진다. 이를 해결하려면 s의 자료형을 char에서 int로 바꿔야 한다.

func3의 경우
-> i가 9번째 돌 때 a는 10억(10^9)에 * 10을 하므로 int의 범위인 21억을     
  넘어가버려서 integer overflow가 발생한다.
  이걸 막으려면 a의 자료형을 long long으로 바꾸거나 22번째 줄에서 10 대신
  10ll 혹은 (long long)으로 강제 형변환을 하여 해결할 수 있다.
*/