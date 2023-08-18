#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
}