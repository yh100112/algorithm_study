#include<bits/stdc++.h>
using namespace std;
int n, c, num;
map<int, int> m;
map<int, int> m2;

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> num;
        m[num]++;
        m2.insert({num, i});
    }

    vector<pair<int,int>> v;
    for(auto& m_ : m){
        v.push_back({m_.first, m_.second});
    }

    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        if(left.second == right.second)
            return m2[left.first] < m2[right.first];
        return left.second > right.second;
    });
    

    for(auto& v_ : v){
        for(int i = 0; i < v_.second; i++)
            cout << v_.first << ' ';
    }
    cout << '\n';
}