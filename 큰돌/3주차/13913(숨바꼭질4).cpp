#include<bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
int n, k,ret;
int a[200004], prev[200004], visited[200004];
vector<int> route;

int main(){
    cin >> n >> k;
    visited[n] = 1;
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == k){
            ret = visited[k];
            break;
        }
        for(auto next : {here-1, here+1, here*2}){
            if(visited[next] == 0){
                if (0 <= next && next <= 100000){
                    visited[next] = visited[here] + 1;
                    prev[next] = here;
                    q.push(next);
                }
            }
        }
    }
    for(int i = k; i != n; i = prev[i]){
        route.push_back(i);
    }
    reverse(route.begin(), route.end());
    cout << ret - 1 << "\n";
    cout << n << " ";
    for(auto v : route)
        cout << v << " ";
}