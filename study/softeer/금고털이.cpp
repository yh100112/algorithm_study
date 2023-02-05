#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
	int w, n; // 배낭의 무게 w, 귀금속의 종류 n
	vector<pair<int,int>> m; // 금속의 무게, 금속의 무게당 가격
	cin >> w >> n;
	m.resize(n);
	for(int i = 0; i < n; i++)
		cin >> m[i].first >> m[i].second;
	
	sort(m.begin(), m.end(), [](auto& left, auto& right){
		return left.second > right.second;
	});

	int result = 0;
	for(int i = 0; i < n; i++){
		if(w > m[i].first){
			result += m[i].first * m[i].second;
			w = w - m[i].first;
		}
		else{
			result += w * m[i].second;
			break;
		}	
	}
	cout << result;
	return 0;
}