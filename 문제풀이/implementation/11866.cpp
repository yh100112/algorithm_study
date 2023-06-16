#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin >> n >> k;
    queue<int> q;
    for(int i = 0; i < n; i++){
        q.push(i+1);
    }
    cout << "<";
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        if(cnt == k){
            if(q.size() == 1) cout << q.front() << ">";
            else              cout << q.front() << ", ";
            q.pop();
            cnt = 0;
            continue;
        }
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
}