#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int s[24][24], ret = INF, n;

int go(vector<int>& a, vector<int>& b){
    pair<int,int> ret;
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){
            if(i == j) continue;
            ret.first += s[a[i]][a[j]];
            ret.second += s[b[i]][b[j]];
        }
    }
    return abs(ret.first - ret.second);
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    // 예를 들어 n = 4인 경우
    // 이진수 0 ~ 15 까지 비트는 4자리이기 떄문에 0~15까지 돌면 15까지의 모든 0과 1의 비트 조합들이 나온다. -> 2^4 = 16가지
    // -> n = 4인 경우의 모든 조합인 16가지의 경우가 됨 ( 이거 자체가 순열 조합을 뽑은 것임 )
    for(int i = 0; i < (1 << n); i++){ // n만큼 비트가 필요하므로 1 << n 범위까지 체크
        if(__builtin_popcount(i) != n / 2) continue; // 팀은 n/2명이므로 비트가 이 수만큼 켜져있을 때만 체크
        vector<int> start, link;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) start.push_back(j); // 비트가 켜져있으면 start팀에
            else link.push_back(j);              // 비트가 꺼져있으면 link팀에
        }
        ret = min(ret, go(start, link));
    }
    cout << ret << '\n';
}