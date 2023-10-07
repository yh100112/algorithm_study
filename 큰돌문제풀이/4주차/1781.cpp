#include<bits/stdc++.h>
using namespace std;
int n, day, lamen, sum;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> day >> lamen;
        v.push_back({day, lamen});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first)
            pq.pop();
    }
    while(pq.size()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum << '\n';
}