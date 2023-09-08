#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,h,ret = INT_MAX;
int visited[34][34];

bool check(){
    // 와 이 로직 생각하는게 미쳤다....
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

// here : 가로선 위치, cnt : 가로에 추가로 놓은 사다리 개수
void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return; // 백트래킹 가지치기
    // 종료 조건 ( i에서 시작해 모두 i에서 끝나는 사다리 상태라면 종료 )
    if(check()){
        ret = min(ret, cnt); // cnt = 현재까지 놓은 사다리의 개수
        return;
    }
    // 가로선
    for(int i = here; i <= h; i++){
        // 세로
        for(int j = 1; j <= n; j++){
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue; // 사다리가 있는지, 앞뒤로 사다리가 있는지
            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}
int main(){
    cin >> n >> m >> h; // 세로 가로 세로선마다 가로선을 놓을 수 있는 위치의 개수
    for(int i = 0; i < m; i++){
        cin >> a >> b; // a번 가로선 위치에 b -> b+1로 이어지는 선
        visited[a][b] = 1;
    }
    go(1, 0);
    cout << (ret == INT_MAX ? -1 : ret) << "\n";
}
/*
visited[1][1] = 가로 1번에 놓는데 세로 1부터 시작해서 오른쪽으로 사다리를 놓는것!! -> 문제를 보고 이렇게 만듬
함수를 호출하면서 가로선 번호를 증가시킬 거임 1 -> 2 -> 3 ...
cnt >= 3 이 경우 종료시킬거임  -> 백트래킹 ( 완탐에서 가지치기 )
최소값이 2로 되어있을 때 그 다음인 3으로 갈 필요 없다 -> 2가 최소인데 그 위는 체크할 필요가 없기 때문
*/