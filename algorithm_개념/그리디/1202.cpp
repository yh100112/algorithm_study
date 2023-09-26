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
    priority_queue<ll> pq; // 일단 해당하면 다 넣어!! 유형

    int j = 0;
    // 모든 가방 ( 작은 가방부터 체크 )
    for(int i = 0; i < k; i++){
        while(j < n && v[j].first <= vv[i]){ // 현재 가방의 제한 무게보다 적은 무게의 보석일 때
            pq.push(v[j].second); // 보석의 가격을 우선순위 큐에 넣음
            j++;
        }
        // while을 빠져나오면 pq에는 이번 가방에 넣을 수 있는 모든 보석의 가격이 내림차순으로 들어가 있음
        // 중요!! -> 가방은 이미 오름차순으로 되어있기 때문에 이전 가방에 넣었던 보석은 다음 가방에도 넣을 수 있음
        // 가방을 먼저 오름차순으로 정렬해두었기 때문!!
        if(pq.size()){
            ret += pq.top(); // 현재 가방에 넣음
            pq.pop();
        }
    }
    cout << ret << '\n';
}