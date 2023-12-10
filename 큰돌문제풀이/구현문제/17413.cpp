#include<bits/stdc++.h>
using namespace std;
int visited[100004];
string s;

int main(){
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '<'){
            while(s[i] != '>')
                i++;
            continue;
        }
        visited[i] = 1;
    }

    int st = 0;
    int ed = 0;
    int flag = 0;
    for(int i = 0; i < s.length(); i++){
        if(!flag && visited[i]){
            st = i;
            flag = 1;
        }
        else if(flag && !visited[i]){
            ed = i;
            reverse(s.begin() + st, s.begin() + ed);
            flag = 0;
        }
    }
    if(flag){
        reverse(s.begin() + st, s.end());
    }
    cout << s << '\n';
}