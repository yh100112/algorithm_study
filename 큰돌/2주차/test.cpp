#include<bits/stdc++.h>
using namespace std;
int n, temp;
vector<int> v;
bool check(int n){
	if(n <= 1) return 0;
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(int i = 2; i * i <= n; i++){
		if (n % i == 0) return 0;
	}
	return 1;
}
int go(int idx, int sum){
    cout << idx << " " << sum << endl;
 	if(idx == n){
		return check(sum);
	}
	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
    // idx + 1 -> 탐색해 나가면서
    // sum + v[idx] -> 포함하거나, sum -> 제외시키거나
}
int main() {
	cin >> n;
    v.resize(n);
	for(int i = 0; i < n; i++)
        cin >> v[i];
	cout << go(0,0) << "\n";
	return 0;
}