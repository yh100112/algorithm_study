#include<bits/stdc++.h>
using namespace std;
int n, sum, lo, hi, ret;
bool check[4000001];
vector<int> v;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(check[i]) continue;
        for(int j = 2 * i; j <= n; j += i)
            check[j] = 1;
    }
    for(int i = 2; i <= n; i++)
        if(!check[i]) v.push_back(i);
    
    while(true){
        if(sum >= n)
            sum -= v[lo++];
        else if(hi == v.size())
            break;
        else if(sum < n)
            sum += v[hi++];
        if(sum == n) ret++;
    }
    cout << ret << '\n';
}