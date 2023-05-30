#include<bits/stdc++.h>
using namespace std;
string word;
int sum;
int main(){ 
    cin >> word;
    for(int i = 0; i < word.size(); i++){
        if('W' <= word[i])
            sum += 10;
        else if('T' <= word[i])
            sum += 9;
        else if('P' <= word[i])
            sum += 8;
        else if('M' <= word[i])
            sum += 7;
        else if('J' <= word[i])
            sum += 6;
        else if('G' <= word[i])
            sum += 5;
        else if('D' <= word[i])
            sum += 4;
        else
            sum += 3;
    }
    cout << sum << '\n';
}