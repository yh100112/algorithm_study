#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, a[104], visited[104], cnt;
vector<int> v;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    
    // 전기제품
    for(int i = 0; i < k; i++){
        if(!visited[a[i]]){
            if(v.size() == n){
                int late_idx = 0; // 가장 나중에 등장하는 전기용품
                int late_goods;
                for(auto cur_num : v){
                    int cur_idx = INF;
                    for(int j = i + 1; j < k; j++)
                        if(a[j] == cur_num){
                            cur_idx = j;
                            break;
                        }
                    if(late_idx < cur_idx){
                        late_idx = cur_idx;
                        late_goods = cur_num;
                    }
                }
                visited[late_goods] = 0;
                v.erase(find(v.begin(), v.end(), late_goods));
                cnt++;
            }
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << cnt << '\n';
}