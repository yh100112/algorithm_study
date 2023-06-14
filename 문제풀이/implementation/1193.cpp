#include<bits/stdc++.h>
using namespace std;
int X;
int cnt, cnt_sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X;
    while(true){
        if(cnt_sum >= X) break;
        cnt++;
        cnt_sum += cnt;
    }
    if(cnt & 1) {
        int x = cnt, y = 1;
        int st = cnt_sum - cnt + 1;
        while(true){
            if(st == X) break;
            st++;
            x--; 
            y++;
        }
        cout << x <<"/" << y << "\n";
    }
    else {
        int x = 1, y = cnt;
        int st = cnt_sum - cnt + 1;
        while(true){
            if(st == X) break;
            st++;
            x++;
            y--;
        }
        cout << x << "/" << y << "\n";
    }
}