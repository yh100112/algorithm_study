#include<bits/stdc++.h>
using namespace std;
int a[4] = {1,2,3,4};
int n = 4, r = 2;

void print(){
    for(int i = 0; i < r; i++)
        cout << a[i] << " ";
    cout << endl;
}

void makePermutation(int n, int r, int depth){
    if(depth == r){
        print();
        return;
    }
    for(int i = depth; i < n; i++){
        swap(a[i], a[depth]);
        makePermutation(n,r,depth+1);
        swap(a[i], a[depth]);
    }
    return;
}

int main(){
    makePermutation(n,r,0);
    return 0;
}