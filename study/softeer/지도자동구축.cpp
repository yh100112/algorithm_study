#include<iostream>
using namespace std;
using ll = long long;
ll D[15];

int main(int argc, char** argv)
{
	int n;
	cin >> n;

	D[0] = 2;
	D[1] = 3;
	ll add = 1;
	for(int i = 2; i <= n; i++){
		add *= 2;
		D[i] = D[i-1] + add;
	}
	cout << D[n] * D[n];
	return 0;
}