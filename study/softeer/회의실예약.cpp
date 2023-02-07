#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
using namespace std;


int main(int argc, char** argv)
{
	int n,m; // n : 회의실의 수, m : 예약된 회의의 수
	string room[n];
	map<string, vector<int>> reserv;
	vector<int> arr(19);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> room[i];
		reserv[room[i]] = arr;
	}
	sort(room,room+n);

	for(int i = 0; i < m; i++){
		string r,s,t;
		cin >> r >> s >> t;
		int start = stoi(s);
		int end = stoi(t);
		for(int j = start; j <= end; j++){
			reserv[r][j] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		vector<pair<int,int>> v;
		int start = 0;
		int end = 0;
		cout << "Room " << room[i] << ":\n";
		for(int j = 9; j <= 18; j++){
			if(reserv[room[i]][j] == 0){
				start = j;
			}
			else {
				if(start != 0)
					end = j;
				v.push_back({start,end});
				start = 0;
				if(j < 18 && reserv[room[i]][j+1] == 0)
					start = j;
			}
		}
		if (v.empty() == true){
			cout << "Not available" << "\n" << "-----" << "\n";
		}
		else {
			cout << v.size() << " available:\n"; 
			for(auto& ans: v){
				cout << ans.first << "-" << ans.second << "\n"; 
			}
			if (i != n-1)
				cout << "-----" << "\n";
		}
	}


	return 0;
}