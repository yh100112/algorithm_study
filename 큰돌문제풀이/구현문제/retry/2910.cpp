#include<bits/stdc++.h>
using namespace std;
int n, c, num;
map<int,int> m;
map<int,int> turn;
vector<pair<int,int>> v;

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> num;
        m[num]++;
        if(turn.find(num) == turn.end())
            turn[num] = i;
    }
    for(auto i : turn) {
        v.push_back({i.first, i.second});
    }
    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        if(m[left.first] == m[right.first])
            return left.second < right.second;
        return m[left.first] > m[right.first];
    });

    for(auto v_ : v) {
        for(int i = 0; i < m[v_.first]; i++)
            cout << v_.first << ' ';
    }
    cout << '\n';
}