#include<bits/stdc++.h>
using namespace std;
int n, k, elec[104], visited[104], ret;
vector<int> tab;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> elec[i];
    
    for (int i = 0; i < k; i++) {
        if (!visited[elec[i]]) {
            if (tab.size() == n) {
                if(find(tab.begin(), tab.end(), elec[i]) == tab.end()) {
                    int last_idx = -1;
                    int num;
                    for (int curr_e : tab) {
                        int idx = INT_MAX;
                        for (int j = i + 1; j < k; j++) {
                            if (elec[j] == curr_e) {
                                idx = j;
                                break;
                            }
                        }
                        // idx == INT_MAX라면 나중에 사용이 안되는 전자기기임 -> 최우선순위로 뺀다!
                        if (last_idx < idx) {
                            last_idx = idx;
                            num = curr_e;
                        }
                    }
                    tab.erase(find(tab.begin(), tab.end(), num));
                    visited[num] = 0;
                    ret++;
                }
            }
            tab.push_back(elec[i]);
            visited[elec[i]] = 1;
        }
    }
    cout << ret << "\n";
}