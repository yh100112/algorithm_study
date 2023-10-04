#include<bits/stdc++.h>
using namespace std;
int n, k, a[100004], cnt;


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    sort(a, a + n);

    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = a[left] + a[right];
        if(sum < k)
            left++;
        else if(sum == k)
            cnt++, right--;
        else if(sum > k)
            right--;
    }
    cout << cnt << '\n';
}