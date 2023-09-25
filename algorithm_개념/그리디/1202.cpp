#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, ret, temp, temp1;

int main(){
    cin >> n >> k;
    vector<pair<ll, ll>> v(n); // 보석 ( 무게, 가격 )
    vector<ll> vv(k);          // 가방
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    for(int i = 0; i < k; i++)
        cin >> vv[i];
    
    sort(v.begin(). v.end());   // 보석을 무게를 기준으로 오름차순 정렬
    sort(vv.begin(). vv.end()); // 가방을 무게를 기준으로 오름차순 정렬
    priority_queue<ll> pq;      // 내림차순이 default
    // pq ->  일단 넣어!! 라고 하는 문제가 굉장히 많음

    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && v[j].first <= vv[i]){ // 현재 가방의 제한 무게보다 적은 무게의 보석일 때
            pq.push(v[j].second);
            j++;
        }
        if(pq.size()){
            ret += pq.top(); // 현재 가방에 넣음
            pq.pop();
        }
    }
    cout << ret << '\n';
}