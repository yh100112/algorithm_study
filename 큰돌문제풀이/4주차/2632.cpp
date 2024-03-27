#include<bits/stdc++.h>
using namespace std;
int a[1001], b[1001], ret, psum_a[2002], psum_b[2002], want, n, m;
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int,int>& mp){
    for(int interval = 1; interval <= n; interval++){ // 1개짜리, 2개짜리, ...
        for(int start = interval; start <= n + interval - 1; start++){
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if(interval == n) break;
        }
    }
}

int main() {
    scanf("%d %d %d", &want, &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        psum_a[i] = psum_a[i - 1] + a[i];
    }
    for(int i = n + 1; i <= 2 * n; i++)
        psum_a[i] = psum_a[i - 1] + a[i - n];
    
    for(int i = 1; i <= m; i++){
        scanf("%d", b + i);
        psum_b[i] = psum_b[i - 1] + b[i];
    }
    for(int i = m + 1; i <= 2 * m; i++)
        psum_b[i] = psum_b[i + m] + b[i - m];
    make(n, psum_a, aCnt); // 모든 경우의 수를 만드는 것
    make(m, psum_b, bCnt);
    ret = (aCnt[want] + bCnt[want]); // 고객이 원하는 크기를 a혼자 , b혼자 하는 경우의 수
    for(int i = 1; i < want; i++) {
        ret += (aCnt[i] * bCnt[want - i]); // 고객이 원하는 크기를 a,b 같이 사용해서 구하는 경우의 수
    }
    cout << ret << "\n";
}