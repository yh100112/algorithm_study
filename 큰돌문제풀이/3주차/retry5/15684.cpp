#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, a, b, visited[34][34], ret = INF;

bool check(){
    for(int i = 1; i <= n; i++){ // 세로
        int start = i;
        for(int j = 1; j <= h; j++){ // 가로
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

void go(int idx, int cnt){
    if(cnt > 3 || ret < cnt) return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }

    for(int row = idx; row <= h; row++){
        for(int col = 1; col <= n; col++){
            if(visited[row][col] || visited[row][col - 1] || visited[row][col + 1]) continue;
            visited[row][col] = 1;
            go(row, cnt + 1);
            visited[row][col] = 0;
        }
    }
}

int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        visited[a][b] = 1;
    }
    go(1, 0);
    cout << (ret == INF ? -1 : ret) << '\n';
}

/*
사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다. 세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.

출력
i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다. 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

5 5 6
1 1
3 2
2 3
5 1
5 4
*/