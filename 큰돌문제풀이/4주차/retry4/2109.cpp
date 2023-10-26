#include<bits/stdc++.h>
using namespace std;
int n, d, p, sum;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> d;
        v.push_back({d, p}); // day, price
    }
    sort(v.begin(), v.end()); // day를 기준으로 오름차순

    for(int i = 0; i < n; i++){
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