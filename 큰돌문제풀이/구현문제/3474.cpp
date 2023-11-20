#include<bits/stdc++.h>
using namespace std;
int t, num, ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> num;
        int two = 1, five = 1;
        int n1 = 0, n2 = 0;
        while(true){
            if(two >= num && five >= num) break;
            if(two < num) {
                two *= 2;
                n1 += num / two;
            }
            if(five < num) {
                five *= 5;
                n2 += num / five;
            }
        }
        ret = min(n1, n2);
        cout << ret << '\n';
    }
}