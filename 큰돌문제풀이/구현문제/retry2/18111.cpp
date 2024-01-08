#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, b, a[504][504], cost[257], t = INF;
vector<int> v;

int main(){
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    fill(&cost[0], &cost[0] + 257, INF);    
    for(int h = 0; h <= 256; h++){
        int remove = 0; // 지워야 할 블록 수
        int add = 0; // 더해야 할 블록 수
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] >= h) remove += (a[i][j] - h);
                else add += (h - a[i][j]);
            }
        }

        if(b + remove >= add){
            int t_ = remove * 2 + add;
            cost[h] = t_;
            t = min(t, t_);
        }
    }
    for(int h = 0; h <= 256; h++)
        if(cost[h] == t)
            v.push_back(h); 
    
    cout << t << ' ' << v.back() << '\n';
}