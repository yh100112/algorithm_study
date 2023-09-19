#include<bits/stdc++.h>
using namespace std;
int flag;

void go(string s, string find_s){
    if(s.size() > find_s.size()) return;
    if(s.size() == find_s.size()){
        if(s == find_s) flag = 1;
        return;
    }

    
    go(s + "a", find_s);
    go("a" + s, find_s);

    string add_to_a = "";
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'a') add_to_a += "b";
    
    s = add_to_a + s;
    s = s + add_to_a;
    go(s, find_s);
}

vector<bool> solution(vector<string> a){
    vector<bool> answer;

    for(int i = 0; i < a.size(); i++){
        string find_s = a[i], start = "a";
        flag = 0;
        while(true){
            if(find_s.size() < start.size()) break;
            if(find_s == start){
                flag = 1;
                break;
            }

        }
        // go(start, find_s);
        if(flag) answer.push_back(true);
        else answer.push_back(false);
    }

    return answer;
}

int main(){
    vector<string> a = {"aaaaaaaaaaaaaaaaaaa", "bbaa", "bababa", "bbbabababbbaa", "bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa","bbbabababbbaa",};
    vector<bool> answer = solution(a);
    for(auto i : answer)
        cout << i << ' ';
    cout << endl;
}
// 내가 푼 방식인 백트래킹으로 풀면 시간복잡도 걸림 -> 그리디로풀어야 된다는데?
// 1번 역으로 지워가면서 풀면되지않나요?