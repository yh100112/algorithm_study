#include<bits/stdc++.h>
using namespace std;
int n, k, cnt, INF = 987654321;
vector<int> v; // 전기 용품 사용 순서
vector<int> c; // 콘센트
int visited[102];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; // 구멍 n, 전기 용품 총 사용 횟수 k 
    v.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> v[i];
    
    for (int i = 0; i < k; ++i) {
        if (!visited[v[i]]) { // 새롭게 꼽아야 하는 전기 용품이 콘센트에 꽂혀있지 않은 경우
            if (c.size() == n) { // 콘센트가 꽉 찬 경우
                int last_idx = -1;
                int erase_product;
                for (auto& product : c) { // 현재 꽂혀있는 용품
                    int idx = INF;
                    for (int j = i + 1; j < k; ++j) {
                        if (v[j] == product) {
                            idx = j;
                            break;
                        }
                    }
                    if (last_idx < idx) {
                        last_idx = idx;
                        erase_product = product;
                    }
                }
                c.erase(find(c.begin(), c.end(), erase_product));
                visited[erase_product] = 0;
                cnt++;
            }
            c.push_back(v[i]);
            visited[v[i]] = 1;
        }
    }
    cout << cnt << "\n";
}