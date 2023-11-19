#include<bits/stdc++.h>
using namespace std;
int n, c, num;
map<int,int> order, m; 
vector<pair<int,int>> cnt;

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> num;
        m[num]++;
        order.insert({num,i});
    }
    for(auto i : m)
        cnt.push_back({i.first, i.second}); // num, cnt
    
    sort(cnt.begin(), cnt.end(), [](pair<int,int>& l, pair<int,int>& r){
        if(l.second == r.second){
            return order[l.first] < order[r.first];
        }
        else{
            return l.second > r.second;
        }
    });


    for(auto v : cnt){
        for(int i = 0; i < v.second; i++)
            cout << v.first << ' ';
    }
    cout << '\n';
}