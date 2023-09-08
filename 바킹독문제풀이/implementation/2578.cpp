#include<bits/stdc++.h>
using namespace std;
int arr[5][5]; // 빙고판
int arr2[5][5]; // 사회자
int bingo[12];

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }

    int n;
    int call = 0;
    int ret = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> arr2[i][j];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            call++;
            int num = arr2[i][j];
            for(int m = 0; m < 5; m++){
                for(int n = 0; n < 5; n++){
                    if(arr[m][n] == num) {
                        arr[m][n] = -1;
                        bingo[m]++;     // 0 1 2 3 4
                        bingo[5 + n]++; // 5 6 7 8 9
                        if (m == n) {
                            bingo[10]++;
                            if (m == 2)
                                bingo[11]++;
                        }
                        if (abs(m-n) == 4 || (m == 1 && n == 3) || (m == 3 && n == 1))
                            bingo[11]++;
                    }
                }
            }
            int cnt = 0;
            for(int m = 0; m < 12; m++){
                if(bingo[m] == 5)
                    cnt++;
                if(cnt == 3) {
                    cout << call;
                    return 0;
                }
            }
        }
    }
}