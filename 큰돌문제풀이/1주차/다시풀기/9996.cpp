#include<bits/stdc++.h>
using namespace std;
int n;
string pat;
string str, st, ed;
int main(){
    cin >> n >> pat;
    for(int i = 0; i < n; i++){
        cin >> str;
        st = pat.substr(0, pat.find('*'));
        ed = pat.substr(pat.find('*') + 1);
        if(str.length() >= st.length() + ed.length()) {
            if((st == str.substr(0,st.length())) && (ed == str.substr(str.length() - ed.length()))){
            cout << "DA" << "\n"; 
            }
            else {
                cout << "NE" << "\n";
            }
        }
        else {
            cout << "NE" << "\n";
        }
    }
}