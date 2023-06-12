#include<bits/stdc++.h>
using namespace std;
int arr[10004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1; i <= 10000; i++){
        string s = to_string(i);
        int ret = 0;
        for(auto v : s) {
            ret += (v - '0');
        }
        ret += i; 
        if(ret <= 10000)
            arr[ret]++; 
    }
    for(int i = 1; i <= 10000; i++){
        if(arr[i] == 0)
            cout << i << "\n";
    }
}