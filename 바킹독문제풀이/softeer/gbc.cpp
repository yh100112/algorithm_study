#include<iostream>
#include<vector>
using namespace std;

vector<int> limit;
vector<int> check;

int main(int argc, char** argv)
{
	int n,m;
	int i,j;
	cin >> n >> m;
	for(i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		for(j = 0; j < a; j++){
			limit.push_back(b);
		}
	}
	for(i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		for(j = 0; j < a; j++){
			check.push_back(b);
		}
	}

	int mx = 0;
	for(i = 0; i < 100; i++){
		mx = max(mx, check[i] - limit[i]); // limit이 더 커서 이 값이 -이면 어차피 안 들어가므로 이렇게 해줌
	}
	cout << mx;
	
	return 0;
}