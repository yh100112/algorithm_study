#include<bits/stdc++.h>
using namespace std;
int n, k, a[1004][8], temp[1004][8], visited[1004], cnt;
string s;
vector<pair<int,int>> v; // 회전

void go(int num, int dir){
    if(visited[num]) return;
    visited[num] = 1;

    if(num > 0 && a[num - 1][2] != a[num][6])
        go(num - 1, dir == -1 ? 1 : -1);
    if(num < n - 1 && a[num + 1][6] != a[num][2])
        go(num + 1, dir == -1 ? 1 : -1);

    if(dir == -1)
        rotate(a[num], a[num] + 1, a[num] + 8); // 반시계
    else
        rotate(a[num], a[num] + 7, a[num] + 8); // 시계

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < 8; j++){
            a[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        int num, dir;
        cin >> num >> dir; 
        num--;
        v.push_back({num, dir});
    }

    // 회전
    for(int i = 0; i < k; i++){
        memset(visited, 0, sizeof(visited));
        go(v[i].first, v[i].second);
    }

    for(int i = 0; i < n; i++)
        if(a[i][0]) cnt++;
    cout << cnt << '\n';
}