#include<bits/stdc++.h>
using namespace std;
int k, a[1030];
vector<int> v[12];

void go(int start, int end, int depth){
    if(start > end) return;
    if(start == end){
        v[depth].push_back(a[start]);
        return;
    }

    int mid = (start + end) / 2;
    v[depth].push_back(a[mid]);
    go(start, mid, depth + 1);
    go(mid + 1, end, depth + 1);
}

int main(){
    cin >> k;
    int _end = (int)pow(2,k) - 1;
    for(int i = 0; i < _end; i++)
        cin >> a[i];
    
    go(0, _end, 0);

    for(int i = 0; i < k; i++){
        for(auto ret : v[i])
            cout << ret << ' ';
        cout << '\n';
    }
}