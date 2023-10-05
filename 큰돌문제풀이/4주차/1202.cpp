#include<bits/stdc++.h>
using namespace std;
int n, k, m, v;
long long sum;
vector<pair<int,int>> jewel;
vector<int> bag;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> m >> v;
        jewel.push_back({m,v});
    }

    bag.resize(k);
    for(int i = 0; i < k; i++)
        cin >> bag[i];
    
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    priority_queue<int> pq;
    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && jewel[j].first <= bag[i]){
            pq.push(jewel[j].second);
            j++;
        }
        if(pq.size()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
}