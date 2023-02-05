#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define X first
#define Y second
string board[25];
int vis[25][25];
vector<int> ans;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// 1 : 장애물, 0 : 도로
int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for(int i = 0 ;i < n; i++)
		cin >> board[i];

	int num = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == '0' || vis[i][j] == 1) continue; // 와 여기서 board가 string배열인지 모르고 0으로 해서 계속틀린거!!
			++num;
			queue<pair<int,int>> Q;
			Q.push({i,j});
			vis[i][j] = 1;
			int cnt = 0;
			while(!Q.empty()){
				++cnt;
				auto cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue; // 와 여기서 board가 string배열인지 모르고 0으로 해서 계속틀린거!! 
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
			ans.push_back(cnt);	 
		}
	}
	sort(ans.begin(),ans.end());
	cout << num << "\n";
	for(auto& v: ans)
		cout << v << "\n";
	return 0;
}