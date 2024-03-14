#include<bits/stdc++.h>
using namespace std;
int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;

int main(){
    cin >> k >> n; // 멀티탭 구멍 갯수, 전기용품 갯수
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    // 사용하는 전기용품 갯수
    for(int i = 0; i < n; i++){
        // 콘센트에 꽂혀있지 않은 전기용품인 경우 
        if(!visited[a[i]]){
            // 콘센트가 꽉 참
            if(v.size() == k){
                int last_idx = 0, pos;
                // 현재 콘센트에 꽂혀있는 전기용품 목록 : v
                for(int _a : v){
                    int here_pick = INF;
                    for(int j = i + 1; j < n; j++){ // 가장 먼 미래에 참조되는 것 확인
                        if(_a == a[j]){
                            here_pick = j;
                            break;
                        }
                    }
                    if(last_idx < here_pick){
                        last_idx = here_pick;
                        pos = _a;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
}
/*
2 7
2 3 2 3 1 2 7

2
*/