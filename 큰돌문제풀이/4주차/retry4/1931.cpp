#include<bits/stdc++.h>
using namespace std;
int a, b, cnt = 1, n;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int l = v[0].first;
    int r = v[0].second;
    for(int i = 1; i < n; i++){
        if(r <= v[i].first){
            l = v[i].first;
            r = v[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;
}