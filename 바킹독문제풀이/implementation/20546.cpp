#include<bits/stdc++.h>
using namespace std;
int m;
int arr[14];

int main(){
    cin >> m;
    for(int i = 0; i < 14; i++)
        cin >> arr[i];
    

    // 준현
    int jun_money = m;
    int jun_stock = 0; // 주식 갯수
    for(int i = 0; i < 14; i++) {
        if (arr[i] <= jun_money) {
            int num = jun_money / arr[i];
            jun_money -= (num * arr[i]);
            jun_stock = num;
        }
    }
    jun_stock *= arr[13];

    // 성민
    int sung_money = m;
    int sung_stock = 0; // 주식 개수
    int raise_cnt = 0;
    int down_cnt = 0;
    for(int i = 1; i < 14; i++) {
        // 전날보다 떨어진 경우
        if(arr[i] < arr[i-1]) {
            if (sung_stock > 0) {
                down_cnt++;
                if(down_cnt == 3) {
                    down_cnt = 0;
                    sung_money += (sung_stock * arr[i]);
                    sung_stock = 0;
                }
            }
        }
        // 전날보다 오른 경우
        else if(arr[i] > arr[i-1]) {
            raise_cnt++;
            if(raise_cnt == 3){
                int num = sung_money / arr[i];
                sung_money -= (num * arr[i]);
                sung_stock = num;
            }
        }
    }
    sung_stock *= arr[13];

    if(sung_stock + sung_money > jun_stock + jun_money) cout << "TIMING";
    else if (sung_stock + sung_money < jun_stock + jun_money) cout << "BNP";
    else cout << "SAMESAME";
}