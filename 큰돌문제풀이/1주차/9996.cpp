#include<bits/stdc++.h>
using namespace std;
int n;
string file;
string pt, pre, suf;

int main(){
    cin >> n >> pt;
    int in = pt.find('*');
    pre = pt.substr(0, in);
    suf = pt.substr(in + 1);
    for(int i = 0; i < n; i++){
        cin >> file;
        if (pre.size() + suf.size() > file.size()) {
            cout << "NE" << "\n";
        }
        else {
            if (pre == file.substr(0,pre.size()) && suf == file.substr(file.size() - suf.size())) {
                cout << "DA" << "\n";
            }
            else {
                cout << "NE" << "\n";
            }
        }
    }
}