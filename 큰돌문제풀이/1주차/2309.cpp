#include<bits/stdc++.h>
using namespace std;
int arr[9];

void res(){
    vector<int> v {0,0,1,1,1,1,1,1,1};
    vector<int> ans;
    do{
        for(int i = 0; i < 9; i++){
            if (v[i] == 1)
                ans.push_back(arr[i]);
        }
        int sum = accumulate(ans.begin(),ans.end(), 0);
        if (sum == 100) {
            for(auto t : ans){
                cout << t << "\n";
            }
            exit(0);
        }
        ans.clear();
    }while(next_permutation(v.begin(), v.end()));
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    sort(arr,arr + 9);
    res();
}