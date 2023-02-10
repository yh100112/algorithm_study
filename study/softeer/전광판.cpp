#include<iostream>
#include<vector>
#include<utility>
using namespace std;

string board[11] = 
{
  "1110111",
  "0010001",
  "0111110",
  "0111011",
  "1011001",
  "1101011",
  "1101111",
  "1110001",
  "1111111",
  "1111011",
  "0000000" // 아무것도 없는 상태
};

int n; // 테스트 케이스 수
vector<pair<string,string>> test_case;

int main(int argc, char** argv)
{	
	cin >> n;
	test_case.resize(n);
	for(int i = 0; i < n; i++){
		string a,b;
		cin >> a >> b;
		int a_len = 5 - a.length();
		int b_len = 5 - b.length();
		string chk;
		chk = "";
		while(a_len--){
			chk += " ";
		}
		a = chk + a;

		chk = "";
		while(b_len--){
			chk += " ";
		}
		b = chk + b;
		
		test_case[i].first = a;
		test_case[i].second = b;
	}


	for(int i = 0; i < n; i++){
		int cnt = 0;
		string a = test_case[i].first;
		string b = test_case[i].second;

		// 5자리 비교
		for(int j = 0; j < 5; j++){
			int aa,bb;
			if(a[j] == ' ')
				aa = 10;
			else
				aa = a[j] - '0';
			
			if(b[j] == ' ')
				bb = 10;
			else
				bb = b[j] - '0';
				
			for(int k = 0; k < 7; k++){
				if(board[aa][k] != board[bb][k])
					cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}