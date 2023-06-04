#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int arr[102];
int st, en;
int ret;

int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        cin >> st >> en;
        for(int j = st; j < en; j++) arr[j]++; // 시작(이상) ~ 끝(미만)
    }
    for(int i = 1; i < 100; i++){
        if(arr[i] == 1) ret += a;
        else if (arr[i] == 2) ret += b * 2;
        else if (arr[i] == 3) ret += c * 3;
    }
    cout << ret << "\n";
}

// counting star!! 카운트를 세줘야 하는 묹제
// 시작 끝이 있는 문제일 때 <범위는 시작은 "이상" 끝은 "미만">