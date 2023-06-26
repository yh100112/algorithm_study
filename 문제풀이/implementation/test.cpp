#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcde";
    s += 'a';
    cout << s << endl;

    int a[2] = {1,2};
    swap(a[0],a[1]);
    for(auto v: a)
        cout << v << " ";
    cout << endl;
    swap(a[0],a[1]);
    for(auto v: a)
        cout << v << " ";
    cout << endl;
}