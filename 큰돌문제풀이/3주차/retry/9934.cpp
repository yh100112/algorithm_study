#include<bits/stdc++.h>
using namespace std;
int k, a[1030];
vector<int> ret[1030];

void go(int start, int end, int depth){
    if(start > end) return;
    if(start == end){
        ret[depth].push_back(a[start]);
        return;
    }
    int _mid = (start + end) / 2;
    ret[depth].push_back(a[_mid]);
    go(start, _mid, depth + 1);
    go(_mid + 1, end, depth + 1);
}

int main(){
    cin >> k;
    int _end = (int)pow(2,k) - 1;
    for(int i = 0; i < _end; i++)
        cin >> a[i];
    go(0, _end, 0);

    for(int i = 0; i < k; i++){
        for(auto t : ret[i])
            cout << t << ' ';
        cout << "\n";
    }
}