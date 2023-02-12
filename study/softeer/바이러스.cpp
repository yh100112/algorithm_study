#include<iostream>
using namespace std;
using ll = long long;

ll func(ll k, ll p, ll n){
	while(n--){
		k = k * p % 1000000007;
	}
	return k;	
}


int main(int argc, char** argv)
{
	ll k,p,n;
	cin >> k >> p >> n;
	cout << func(k,p,n);
	return 0;
}