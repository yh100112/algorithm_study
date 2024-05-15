#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> m;

int main(){
    m[1].push_back(1);
    m[1].push_back(2);
    m[1].push_back(3);
    m[2].push_back(3);
    m[2].push_back(3);
    for (pair<int,vector<int>> i : m) {
        cout << i.first << " : ";
        for (int j : i.second)
            cout << j << " ";
        cout << endl;
    }
}