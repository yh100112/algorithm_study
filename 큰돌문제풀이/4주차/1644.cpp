#include<bits/stdc++.h>
using namespace std;
bool check[4000001];
int n, a[2000001], p, lo, hi, ret, sum;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(check[i]) continue;
        for(int j = 2 * i; j <= n; j += i)
            check[j] = 1;
    }
    for(int i = 2; i <= n; i++)
        if(!check[i]) a[p++] = i; // a[] = 소수 집합 

    while(true){
        if(sum >= n)
            sum -= a[lo++];
        else if(hi == p) 
            break;
        else if(sum < n)
            sum += a[hi++];
        if(sum == n) ret++;
    }
    cout << ret << '\n';
}