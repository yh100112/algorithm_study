#include<bits/stdc++.h>
using namespace std;
int n, p, d, sum;
vector<priority_queue<int>> v(10004);

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> d;
        v[d].push(p);
    }
    int j = 0;
    for(int day = 1; day <= 10000; day++){
        if(v[day].size()){
            sum += v[day].top();
        }
    }
    cout << sum << '\n';
}