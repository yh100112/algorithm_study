#include<bits/stdc++.h>
using namespace std;
int n, m, num, k;
int ret;
int arr[11];

int main(){
    cin >> n >> m;
    cin >> num;
    for(int i = 1; i <= m; i++)
        arr[i] = 1;
    
    int st = 1;
    int ed = m;
    for(int i = 0; i < num; i++){
        cin >> k;
        if (st <= k && k <= ed) {
            continue;
        }
        else {
            if (k > ed) {
                while(true) {
                    if (st <= k && k <= ed)
                        break;
                    ret++;
                    arr[st] = 0;
                    st = st + 1;
                    ed = ed + 1;
                    for(int j = st; j <= ed; j++)
                        arr[j] = 1;
                }
            }   
            else {
                while(true) {
                    if (st <= k && k <= ed)
                        break;
                    ret++;
                    arr[ed] = 0;
                    st = st - 1;
                    ed = ed - 1;
                    for(int j = st; j <= ed; j++)
                        arr[j] = 1;
                }
            }
        }
    }
    cout << ret;
}