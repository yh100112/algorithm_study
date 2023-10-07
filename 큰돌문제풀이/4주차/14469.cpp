#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int,int>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    int s = v[0].first;
    int e = s + v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first >= e){
            s = v[i].first;
            e = s + v[i].second;
        }
        else{
            s = e;
            e = s + v[i].second;
        }
    }
    cout << e << '\n';
}