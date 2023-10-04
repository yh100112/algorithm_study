#include<bits/stdc++.h>
using namespace std;
int n, k;
long long ret;
vector<pair<int,int>> jewel;
vector<int> bag;


int main(){
    cin >> n >> k;
    jewel.resize(n);
    bag.resize(k);
    for(int i = 0; i < n; i++)
        cin >> jewel[i].first >> jewel[i].second; // weight, price
    for(int i = 0; i < k; i++)
        cin >> bag[i];
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());

    priority_queue<int> pq;
    int j = 0;
    for(int i = 0; i < bag.size(); i++){
        while(j < n && jewel[j].first <= bag[i]){
            pq.push(jewel[j].second);
            j++;
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
}