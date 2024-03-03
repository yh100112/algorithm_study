#include<bits/stdc++.h>
using namespace std;
int n, c, num;
map<int, int> m1, m2;

int main(){
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        m1[num]++;
        m2.insert({num, i});
    }

    vector<pair<int,int>> v;
    for (auto& i : m1)
        v.push_back({i.first, i.second});
    
    sort(v.begin(), v.end(), [](pair<int,int>& left, pair<int,int>& right){
        if (left.second != right.second)
            return left.second > right.second;
        else
            return m2[left.first] < m2[right.first];
    });

    for (auto& i : v)
        for (int j = 0; j < i.second; ++j)
            cout << i.first << ' ';
    cout << "\n";
}