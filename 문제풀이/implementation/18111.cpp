#include<bits/stdc++.h>
using namespace std;
int n,m,b, ret, sum;
int ar[504][504];
int height[257];

int main(){
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
            height[ar[i][j]]++;
            sum += ar[i][j];
        }
    }
    int max = *max_element(height + 1, height + n * m); // 가장 많은 높이
    int min = *min_element(height + 1, height + n * m); // 가장 적은 높이
    int avg = round(sum / double(n * m)); // 평균 높이
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cur_h = ar[i][j];
            int diff = abs(cur_h - avg);
            if(cur_h > avg){
                ret += (diff) * 2;
                b += (diff);
            }
            else if (cur_h < avg) {
                if(diff <= b) { // 인벤토리에 블록이 충분하면
                    b -= (diff); // 인벤토리에서 필요한 만큼 뻄
                    ret += (diff); // 걸린 시간
                }
                else {
                    avg = cur_h;
                    break;
                }
            }
        }
    }
    cout << ret << " " << avg << "\n";
}