#include<bits/stdc++.h>
using namespace std;
int n,x,y, ret;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    ret = 100 * n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        x = v[i].first;
        y = v[i].second;
        for(int j = i+1; j < n; j++){
            int x2 = v[j].first;
            int y2 = v[j].second;
            if(abs(x-x2) < 10 && abs(y-y2) < 10) {
                ret -= (10 - abs(x - x2)) * (10 - abs(y - y2));
            }
        }
    }
    cout << ret << "\n";
}