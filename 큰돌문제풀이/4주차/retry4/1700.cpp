#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, a[104], visited[104], ret;
vector<int> v;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    
    for(int i = 0; i < k; i++){
        // 콘센트에 이번 전기용품이 꽂혀있지 않으면
        if(!visited[a[i]]){
            if(v.size() == n){
                // 가장 나중에 사용되는 전기용품을 뺀다.
                // 사용되지 않는 전기용품을 뺀다.
                int latest_idx = 0, pos;
                for(auto elec : v){
                    int curr_idx = INF;
                    for(int j = i + 1; j < k; j++){
                        if(a[j] == elec){
                            curr_idx = j;
                            break;
                        }
                    }
                    if(curr_idx > latest_idx){
                        latest_idx = curr_idx;
                        pos = elec;
                    }
                }
                v.erase(find(v.begin(), v.end(), pos));
                visited[pos] = 0;
                ret++;
            }
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << ret << '\n';
}