#include<bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1,2,3,4,5};
void print(vector<int> b){
    for(int i : b) cout << i+1 << " ";
    cout << "\n";
}
void combi(int start, vector<int> b){
    if(b.size() == k){
        print(b);
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i); // vecotr b에는 index를 넣어줌. (실제 값이 아닌 인덱스를 넣어줘야 중복 방지에도 편함)
        combi(i,b);
        b.pop_back();
    }
    return;
}
int main(){
    vector<int> b;
    // combi(-1,b); // 뽑는 수가 4개 이상이면 재귀로 푸는게 나음

    // 뽑는 수가 3개 이하라면 이렇게 반복문으로 구현하는게 더 편하고 빠름
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}

/*
- 순서 상관있이 뽑는 것
1 2 3 
1 2 4
1 2 5
...
3 4 5
이처럼 오름차순(or 내림차순)으로 3개 뽑은 순열이 순서대로 출력되도록 하는 것은 순열

1 2 5
1 3 5
...
1 2 3
이처럼 3개 뽑은 순열이 다 출력되기만 하면 되는 것은 조합
*/