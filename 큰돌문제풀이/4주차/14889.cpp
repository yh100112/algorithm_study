#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[24][24], check[24], ret = INF, sum_s, sum_l;
vector<vector<int>> start, link;

void combi(int idx, vector<int> b){
    if(b.size() == n / 2){
        fill(&check[0], &check[0] + 24, 0);
        start.push_back(b);
        for(int i = 0; i < b.size(); i++)
            check[b[i]] = 1;

        vector<int> v;
        for(int i = 0; i < n; i++)
            if(!check[i]) v.push_back(i);
        link.push_back(v);
        return;
    }

    for(int i = idx + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

void combi2(int idx, int& sum, vector<int> b, vector<int>& v){
    if(b.size() == 2){
        sum += a[v[b[0]]][v[b[1]]];
        sum += a[v[b[1]]][v[b[0]]];
        return;
    }

    for(int i = idx + 1; i < v.size(); i++){
        b.push_back(i);
        combi2(i, sum, b, v);
        b.pop_back();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> v;
    combi(-1, v);

    for(int i = 0; i < start.size(); i++){
        vector<int> s = start[i];
        vector<int> l = link[i];
        vector<int> b;
        sum_s = 0, sum_l = 0;
        combi2(-1, sum_s, b, s);
        combi2(-1, sum_l, b, l);
        ret = min(ret, abs(sum_s - sum_l));
    }
    cout << ret << '\n';
}