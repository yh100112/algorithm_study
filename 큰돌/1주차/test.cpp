#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 111;
    string b = to_string(a);
    for(auto v : b) {
        if(v == '1') cout << v << "\n";
    }
}