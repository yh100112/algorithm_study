#include<bits/stdc++.h>
using namespace std;
#define prev aaaa
const int _max = 100000;
int n, k, visited[_max + 4], prev[_max + 4];
queue<int> q;
vector<int> route;

int main(){
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);

    while(q.size()){
        auto cur = q.front();
        q.pop();
        for(auto next : {cur - 1, cur + 1, cur * 2}){
            if(0 <= next && next <= _max){
                if(!visited[next]){
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                    prev[next] = cur;
                }
            }
        }
    }

    for(int i = k; i != n; i = prev[i])
        route.push_back(i);        
    reverse(route.begin(), route.end());
    cout << visited[k] - 1 << '\n';
    cout << n << ' ';
    for(auto p : route){
        cout << p << ' ';
    }
}