#include<bits/stdc++.h>
using namespace std;
int k;
pair<int,int> len[12];

int main(){
    cin >> k;
    int a,b;
    for(int i = 0; i < 6; i++){
        cin >> a >> b;
        len[i] = {a,b};
        len[i + 6] = {a,b};
    }

    int big, small;
    for(int i = 3; i < 12; i++){
        if(len[i - 2].first == len[i].first && len[i - 1].first == len[i + 1].first) {
            big = len[i + 2].second * len[i + 3].second;
            small = len[i - 1].second * len[i].second;
            break;
        }
    }
    cout << k * (big - small);
}