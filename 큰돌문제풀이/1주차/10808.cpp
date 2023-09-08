#include<bits/stdc++.h>
using namespace std;
int arr[26];
string input;
int main(){
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        arr[input[i] - 'a']++;
    }
    for(auto i : arr) cout << i << " ";
    cout << "\n";
}