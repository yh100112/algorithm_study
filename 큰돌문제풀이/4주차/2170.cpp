#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());
    int left = v[0].first;
    int right = v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first > right){
            ret += (right - left);
            left = v[i].first;
            right = v[i].second;
        }
        else if(v[i].second > right && v[i].first <= right){
            right = v[i].second;
        }
    }
    ret += (right - left);
    cout << ret << '\n';
}