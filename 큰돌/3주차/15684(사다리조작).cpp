/*
사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.
만약, 정답이 3보다 큰 값이면 -1을 출력. 또, 불가능한 경우에도 -1을 출력한다.
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, a, b, ret = INF, visited[34][34];
bool check(){
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

void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return; // 사다리 갯수가 3보다 크거나 이미 최솟값보다 사다리 갯수가 크면 종료
    if(check()){
        ret = min(ret, cnt);
        return;
    }
    for(int i = here; i <= h; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1; // 사다리를 놓는다.
            go(i, cnt + 1);
            visited[i][j] = 0; // 놓은 사다리를 다시 없앤다.
        }
    }
}

int main(){
    cin >> n >> m >> h; // n : 세로선 , m : 가로선, h : 가로선을 놓을 수 있는 위치
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        visited[a][b] = 1; // 1 -> 2 로 오른쪽으로 사다리를 놓는 것
    }
    go(1, 0); // 세로 사다리 1부터 시작
    cout << (ret == INF ? -1 : ret) << "\n";
}