#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int m,n,k; // m : 비밀 메뉴 조작법 , n : 사용자의 입력 버튼, k : 버튼의 정수 범위
	cin >> m >> n >> k;

	char secret[m];
	char input[n];
	string sec,inp;
	for(int i = 0; i < m; i++) {
		cin >> secret[i];
		sec += secret[i];
	}
		
	for(int i = 0; i < n; i++) {
		cin >> input[i];
		inp += input[i];
	}
	
	
	if(inp.find(sec) == string::npos)
		cout << "normal";
	else
		cout << "secret";
	return 0;
}