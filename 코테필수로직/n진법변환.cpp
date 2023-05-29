#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n = 100;
    int b = 2; // 이 숫자를 3으로 바꾸면 10진법 -> 3진법으로 바꾸는 거로 됨
    while(n > 1){
        v.push_back(n % b);
        n /= b;
    }
    if(n == 1) v.push_back(1);
    reverse(v.begin(), v.end());

    for(int a : v){
        if(a >= 10) cout << char(a + 55); // 16진법 변환을 위해 필요
        else cout << a;
    }
}