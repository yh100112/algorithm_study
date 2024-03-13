#include<bits/stdc++.h>
using namespace std;
int cnt = 1;
string num, db = "1234567890", ret;

int main() {
    cin >> num;    
    num[0] == '0' ? ret = '0' : ret = num[0] + to_string(num[0] - '0' + 1); 
    
    for (int i = 1; i < num.length(); ++i) {
        if (ret.back() == num[i]) continue;
        cnt++;
        num[i] == '0' ? ret += '0' : ret += (num[i] + to_string(num[i] - '0' + 1)); 
        if (ret.back() != num[i + 1]) {
            ret.erase(ret.end() - 1);
            cnt++;
        }
        if (ret == num)
            break;
    }
    cout << cnt << "\n";
}