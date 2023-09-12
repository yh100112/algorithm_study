#include<bits/stdc++.h>
using namespace std;
#define prev aaa
const int MAX = 100000;
int n, k, visited[MAX+4], prev[MAX+4]; 
vector<int> route;

int main(){
    cin >> n >> k;
    queue<int> q;
    visited[n] = 1;
    q.push(n);

    while(q.size()){
        auto cur = q.front(); q.pop();
        if(cur == k){
            break;
        }
        for(auto next : {cur-1, cur+1, cur*2}){
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    visited[next] = visited[cur] + 1;
                    prev[next] = cur;
                    q.push(next);
                }
            }
        }
    }
    cout << visited[k] - 1 << "\n";

    for(int i = k; i != n; i = prev[i]){
        route.push_back(i);
    }
    reverse(route.begin(), route.end());
    cout << n << ' ';
    for(auto i : route)
        cout << i << ' ';
    cout << '\n';
}

/*
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다. -> bfs
둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.
*/