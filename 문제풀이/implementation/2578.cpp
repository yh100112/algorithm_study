#include<bits/stdc++.h>
using namespace std;
int arr[5][5]; // 빙고판
int bingo[13];

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }

    int n;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> n;
            for(int a = 1; a <= 5; a++)
                for(int b = 1; b <= 5; b++)
                    if(arr[a][b] == n) {
                        arr[a][b] = 0;
                        bingo[a]++;
                        bingo[5 + b]++;
                        if (a == b) {
                            bingo[11]++;
                            if (a == 3) bingo[12]++;
                        }
                    }
        }
    }
}