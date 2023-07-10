#include<bits/stdc++.h>
using namespace std;
string num;
int n;

int main(){
    cin >> num >> n;
    int arr[10] = {0,};
    int cnt = 0;
    int ret = -1;
    for(int i = 0; i < num.length(); i++){
        string s = "";
        for(int j = i; j < num.length(); j++){
            int a = num[j] - '0';
            if(a <= n && arr[a] == 0 && cnt < n) {
                s += to_string(a);
                arr[a]++;
            }
            cnt++;
        }
        if (s.length() == n) {
            cout << s << " ";
            ret = max(ret, stoi(s));
        }
        fill(arr, arr+10, 0);
        cnt = 0;
    }    
    cout << endl;
    cout << ret;
}