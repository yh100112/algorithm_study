#include<iostream>
#include<map>
using namespace std;
map<char,string> board =
{
  {'0', "1110111"},
  {'1', "0010001"},
  {'2', "0111110"},
  {'3', "0111011"},
  {'4', "1011001"},
  {'5', "1101011"},
  {'6', "1101111"},
  {'7', "1110001"},
  {'8', "1111111"},
  {'9', "1111011"},
  {' ', "0000000"},
};

int n; // 테스트 케이스 수
int main(int argc, char** argv)
{	
	cin >> n;
  
	for(int i = 0; i < n; i++){
		string a,b;
		cin >> a >> b;
		int a_len = 5 - a.length();
		int b_len = 5 - b.length();
		while(a_len--) a = ' ' + a;
		while(b_len--) b = ' ' + b;
		
    int cnt = 0;
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 7; k++)
				if(board[ a[j] ][k] != board[ b[j] ][k]) cnt++;
		cout << cnt << '\n';
	}
	return 0;
}