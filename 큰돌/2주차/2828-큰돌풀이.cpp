#include<bits/stdc++.h>
using namespace std;
int n, m, j, l, r, temp, ret;
int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i = 0; i < j; i++){
        r = l + m -1;
        cin >> temp;
        if (l <= temp && temp <= r) continue;
        else {
            if (temp < l) {
                ret += (l - temp);
                l = temp;
            }
            else {
                ret += (temp - r);
                l += (temp - r);
            }
        }
    }
    cout << ret;
}