#include<bits/stdc++.h>
using namespace std;
const int line[12][5] ={
    {0,1,2,3,4},
    {5,6,7,8,9},
    {10,11,12,13,14},
    {15,16,17,18,19},
    {20,21,22,23,24},
    {0,5,10,15,20},
    {1,6,11,16,21},
    {2,7,12,17,22},
    {3,8,13,18,23},
    {4,9,14,19,24},
    {0,6,12,18,24},
    {4,8,12,16,20}
};
int temp[25], n, flag, ans;
map<int,int> m;

bool bingo(){
    int ret = 0;
    for(int i = 0; i < 12; i++){
        int cnt = 0;
        for(int j = 0; j < 5; j++){
            if(temp[line[i][j]])
                cnt++;
        }
        if(cnt == 5) ret++;
    }
    if(ret >= 3) return true;
    return false;
}

int main(){
    for(int i = 0; i < 25; ++i){
        cin >> n;
        m[n] = i; // 숫자, 위치
    }

    for(int i = 0; i < 25; ++i){
        cin >> n;
        temp[m[n]] = 1;
        if(!flag && bingo()){
            flag = 1;
            ans = i + 1;
        }
    }
    cout << ans << '\n';
}