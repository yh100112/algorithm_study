#include<bits/stdc++.h>
using namespace std;
int arr[10001];
int n, m, ret;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int sum = 0, s = 0, e = 0, result = 0;
    while(true) {
        if (sum >= m) sum -= arr[s++];
        else if (e == n) break; // 앞에 if에서 안걸린 것은 sum이 m보다 작다는 것인데 이때는 무조건 sum을 증가시켜줘야 하는데 e가 이미 끝이므로 종료
        else sum += arr[e++];
        if (sum == m) ret++;
    }
    cout << ret << '\n';
}