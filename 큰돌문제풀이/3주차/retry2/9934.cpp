#include<bits/stdc++.h>
using namespace std;
int k, a[1030];
vector<int> ret[10];

void go(int start, int end, int depth){
    if(start > end) return;
    if(start == end){
        return;
    }
    int mid = (start + end) / 2;
    ret[depth].push_back(a[mid]);

    go(start, mid, depth + 1);
    go(mid + 1, end, depth + 1);
}

int main(){
    cin >> k;
    int n = (int)pow(2,k) - 1;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    go(0, n, 0);

    for(int i = 0; i < k; i++){
        for(auto p : ret[i])
            cout << p << ' ';
        cout << '\n';
    }
}