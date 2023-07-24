#include<bits/stdc++.h>
using namespace std;
string s;
int n, team_num; // n <= 100
int score[3];
int curr_win_team;
int ret[3];
string real_ret[3];
map<int, queue<int>> m;

int change(string s){
    stringstream ss;
    string a;
    ss.str(s);
    int sec = 0;
    int cnt = 0;
    while(getline(ss, a, ':')) {
        cnt++;
        if (cnt == 1) sec += stoi(a) * 60;
        else          sec += stoi(a); 
    }
    return sec;
}

void answer(){
    int minute1 = ret[1] / 60;
    int sec1 = ret[1] % 60;
    int minute2 = ret[2] / 60;
    int sec2 = ret[2] % 60;

    printf("%02d:%02d\n", minute1, sec1);
    printf("%02d:%02d\n", minute2, sec2);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> team_num >> s;
        int sec = change(s);
        score[team_num]++;
        if(score[1] > score[2]) {
            curr_win_team = 1;
            m[curr_win_team].push(sec); // queue에 넣음
        }
        else if(score[1] < score[2]) {
            curr_win_team = 2;
            m[curr_win_team].push(sec); // queue에 넣음
        }
        else {
            ret[curr_win_team] += (sec - m[curr_win_team].front());
            m[curr_win_team].pop();
            curr_win_team = 0;
        }
    }
    if(curr_win_team != 0)
        ret[curr_win_team] += (48 * 60 - m[curr_win_team].front());
    
    answer();
}