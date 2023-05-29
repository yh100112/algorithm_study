#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n,m; // 회의실의 수, 예약된 회의 수
	cin >> n >> m;

	map<string,vector<int>> reserv;
	vector<int> a(18);
	string name[3];
	string r,s,t;
	for(int i = 0; i < n; i++){
		cin >> name[i];
		reserv[name[i]] = a;
	}
	sort(name, name+3);

	for(int i = 0; i < m; i++){
		cin >> r >> s >> t;
		for(int j = stoi(s); j < stoi(t); j++){
			reserv[r][j] = 1;
		}
		
	}

	for(int i = 0; i < n; i++){
		cout << "Room " << name[i] << ":\n";
		int check = 1;
		int start, end;
		vector<pair<int,int>> v;
		for(int j = 9; j < 18; j++){
			if(reserv[name[i]][j] == 0 && check == 1){
				start = j;
				check = 0;
			}
			else if(reserv[name[i]][j] == 1 && check == 0){
				end = j;
				check = 1;
				v.push_back({start,end});
			}
		}
		if(check == 0)
			v.push_back({start,18});
		
		if(v.empty())
			cout << "Not available\n";
		else{
			cout << v.size() << " available:\n";
			for(auto& ans: v){
				if (ans.first == 9)
					cout << "09-" << ans.second << "\n";
				else
					cout << ans.first << "-" << ans.second << "\n";
			}
		}
		if(i < n-1)
			cout << "-----\n";
	}
	return 0;
}