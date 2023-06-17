#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    cout << *max_element(arr + 1, arr + 2) << endl;
}