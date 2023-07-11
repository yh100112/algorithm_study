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

        }
        // 전날보다 오른 경우
        else if(arr[i] > arr[i-1]) {

        }
    }
}