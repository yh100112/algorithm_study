#include<bits/stdc++.h>
using namespace std;
int n,a;
int sum;
vector<int> v;
int arr[4005]; // 양수
int arr2[4005]; // 음수

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
        if(a >= 0) arr[a]++;
        else arr2[abs(a)]++;
    }
    int a = *max_element(arr, arr + 4001); // 양수
    int b = *max_element(arr2 + 1, arr2 + 4001); // 음수
    int mx = max(a,b); // 빈도수

    for(int i = 0; i < 4; i++){
        if(i == 0){
            sum = accumulate(v.begin(), v.end(), 0);
            int ret = round((double)sum / n);
            cout << ret << "\n";
        }
        else if(i == 1) {
            sort(v.begin(), v.end());
            cout << v[v.size() / 2] << "\n";
        }
        else if(i == 2){
            vector<int> mxs;
            for(int j = 0; j < 4001; j++){
               if(mx == arr[j]) {
                    mxs.push_back(j);
               }
               if(mx == arr2[j]) {
                    mxs.push_back(-j);
               }
            } 
            if(mxs.size() == 1){
                cout << mxs.front() << "\n";
            }
            else {
                sort(mxs.begin(), mxs.end());
                cout << mxs[1] << "\n";
            }
        }
        else {
           int mx = *max_element(v.begin(),v.end());
           int mn = *min_element(v.begin(), v.end()); 
           cout << mx - (mn) << "\n";
        }
    }
}