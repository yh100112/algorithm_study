#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int n, sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;
    for(int i = 1; i < n; i++){
        if(r < v[i].first){
            sum += (r - l);
            l = v[i].first;
            r = v[i].second;
        }
        else if(v[i].second > r && v[i].first <= r){
            r = v[i].second;
        }
    }
    sum += (r - l);
    cout << sum << '\n';
}