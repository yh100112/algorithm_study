#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> jewel;
vector<int> bag;
int n, k, m, v, c;
long long ret;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> m >> v;
        jewel.push_back({m,v}); // 무게, 가격
    }
    for(int i = 0; i < k; i++){
        cin >> c;
        bag.push_back(c);
    }

    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    priority_queue<int> pq;
    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && bag[i] >= jewel[j].first){
            pq.push(jewel[j].second);
            j++;
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << endl;
}