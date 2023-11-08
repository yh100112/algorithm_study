#include<bits/stdc++.h>
using namespace std;
int n, a[24][24], ret = 987654321;
vector<int> start, link;

int cal(){
    pair<int,int> c;
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){
            if(i == j) continue;
            c.first += a[start[i]][start[j]];
            c.second += a[link[i]][link[j]];
        }
    }
    return abs(c.first - c.second);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    
    for(int i = 0; i < (1 << n); i++){
        if(__builtin_popcount(i) != n / 2) continue;
        start.clear();
        link.clear();
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) start.push_back(j);
            else link.push_back(j);
        }
        ret = min(ret, cal());
    }
    cout << ret << '\n';
}