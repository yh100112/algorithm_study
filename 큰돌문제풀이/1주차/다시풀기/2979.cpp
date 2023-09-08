#include<bits/stdc++.h>
using namespace std;
int a,b,c,s,e;
int cnt[104];

int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        cin >> s >> e;
        for(int j = s; j < e; j++) {
            cnt[j]++;
        }
    }
    int sum = 0;
    for(int i = 0; i < 104; i++){
        if(cnt[i] == 3) {
            sum += (cnt[i] * c);
        }
        else if(cnt[i] == 2) {
            sum += (cnt[i] * b);
        }
        else if(cnt[i] == 1) {
            sum += (cnt[i] * a);
        }
    }
    cout << sum << "\n";
}