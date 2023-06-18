#include<bits/stdc++.h>
using namespace std;
string str;
int arr[130];

int main(){
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        arr[str[i]]++;
    }
    string ret = "";
    int remain = 0;
    bool flag = 0;
    for(int i = 'Z'; i >= 'A'; i--){
        if(arr[i] % 2 != 0){
            if(flag == 1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            arr[i]--;
            remain = i;
            for(int j = 0; j < arr[i]; j += 2){
                ret = char(i) + ret;
                ret += char(i);
            }
            flag = 1;
        }
        else {
            for(int j = 0; j < arr[i]; j += 2){
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if(remain) {
        int mid = ret.length() / 2;
        ret.insert(ret.begin() + mid, char(remain));
    }
    cout << ret << endl;
}