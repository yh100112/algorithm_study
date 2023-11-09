#include<bits/stdc++.h>
using namespace std;
int n, s, e, visited[4000004];
long long ret;
vector<int> num; // 연속된 소수

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(visited[i]) continue;
        for(int j = i * 2; j <= n; j += i)
            visited[j] =1;
    }
    for(int i = 2; i <= n; i++)
        if(!visited[i]) num.push_back(i);
    
    int sum = 0;
    while(s < num.size()){
        if(e < num.size() && sum < n) sum += num[e++];
        else if(sum == n){
            ret++;
            sum -= num[s++];
        }
        else sum -= num[s++];
    }
    cout << ret << '\n';
}