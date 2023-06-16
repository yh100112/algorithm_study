#include<bits/stdc++.h>
using namespace std;
int p, a, k, n, ret;

int main(){
    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> n >> k; // k : 몇번째
        queue<pair<int,int>> q;
        vector<int> ss; // 우선순위
        for(int j = 0; j < n; j++){
            cin >> a;
            if (j == k)   q.push({a,1});
            else          q.push({a,0});
            ss.push_back(a);
        }
        sort(ss.begin(),ss.end());
        int max = ss.back();
        int cnt = 0;
        int prio = 0, turn = -1;
        while(!q.empty()){
            prio = q.front().first;
            turn = q.front().second;
            if(prio == max) { // 우선순위가 max
                if(turn == 1){
                    cout << cnt + 1 << "\n";
                    break;
                }
                else {
                    q.pop();
                    ss.pop_back();
                    max = *max_element(ss.begin(), ss.end());
                    cnt++;
                }
            }
            else {
                q.pop();
                q.push({prio, turn});
            }
        }
    }
}