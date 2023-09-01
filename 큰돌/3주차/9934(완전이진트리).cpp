#include<bits/stdc++.h>
using namespace std;
int n, a[1030], max_level;
vector<int> ret[11];

void go(int start, int end, int level){
    if(start == end){
        max_level = level;        
        return;
    }

    int mid = (start + end) / 2;
    ret[level].push_back(a[mid]);
    go(start, mid, level+1);
    go(mid+1, end, level+1);
}

int main(){
    cin >> n;
    int _end = (int)pow(2,n) - 1;    
    for(int i = 0; i < _end; i++) cin >> a[i];
    go(0, _end, 0);
    for(int i = 0; i < max_level; i++){
        for(auto v : ret[i]){
            cout << v << " ";
        }
        cout << "\n";
    }
}