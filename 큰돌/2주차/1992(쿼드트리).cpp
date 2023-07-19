#include<bits/stdc++.h>
using namespace std;
int n;
char arr[101][101];

string solve(int y, int x, int size) {
    if(size == 1) return string(1, arr[y][x]);
    char b = arr[y][x];
    string ret = "";
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if (b != arr[i][j]) {
                ret += "(";
                ret += solve(y, x, size / 2);
                ret += solve(y, x + size / 2, size / 2);
                ret += solve(y + size / 2, x, size / 2);
                ret += solve(y + size / 2, x + size / 2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, arr[y][x]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    cout << solve(0,0,n) << "\n";
}