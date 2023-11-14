#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[24][24], ret = INF;

void go(vector<int>& start, vector<int>& link){
    pair<int,int> p;
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){
            if(i == j) continue;
            p.first += a[start[i]][start[j]];
            p.second += a[link[i]][link[j]];
        }
    }
    ret = min(ret, abs(p.first - p.second));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++){
        if(__builtin_popcount(i) != n / 2) continue;
        vector<int> start, link;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) start.push_back(j);
            else link.push_back(j);
        }
        go(start, link);
    }
    cout << ret << '\n';
}