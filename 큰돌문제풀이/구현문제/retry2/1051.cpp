#include<bits/stdc++.h>
using namespace std;
int a[54][54], n, m, ret = -987654321;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';            
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int d = 1;
            while(true){
                bool flag = true;
                if(j + d >= m || i + d >= n) break;
                if(a[i][j] != a[i][j + d]) flag = false;                 
                if(a[i][j] != a[i + d][j]) flag = false;
                if(a[i][j] != a[i + d][j + d]) flag = false;

                if(flag)
                    ret = max(ret, (d+1) * (d+1));
                d++;
            }
            ret = max(ret, 1); 
        }
    }
    cout << ret << '\n';
}