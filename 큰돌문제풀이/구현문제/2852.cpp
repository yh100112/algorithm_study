#include<bits/stdc++.h>
using namespace std;
#define time aaa
int n, a, win_num, score[3], ret[3], start_sec, end_sec, m, s;
string time, curr_win_start_time;

int cal(string start, string end){
    m = stoi(start.substr(0, start.find(":"))) * 60;
    s = stoi(start.substr(start.find(":") + 1));
    start_sec = m + s;

    m = stoi(end.substr(0, end.find(":"))) * 60;
    s = stoi(end.substr(end.find(":") + 1));
    end_sec = m + s;

    return end_sec - start_sec;
}

int main(){
    cin >> n;
    cin >> a >> time;
    score[a]++;
    win_num = a;
    curr_win_start_time = time;

    for(int i = 1; i < n; i++){
        cin >> a >> time; // 득점한 팀 번호, 득점 시간
        score[a]++;
        if(score[1] == score[2]){
            ret[win_num] += cal(curr_win_start_time, time);
            win_num = 0;
            curr_win_start_time = "";
        }
        else{
            int w = score[1] > score[2] ? 1 : 2;
            if(w != win_num){
                win_num = w;
                curr_win_start_time = time;
            }
        }
    }
    if(win_num)
        ret[win_num] += cal(curr_win_start_time, "48:00");
    
    for(int i = 1; i <= 2; i++){
        string m = to_string(ret[i] / 60);
        string s = to_string(ret[i] % 60);
        if(m.size() == 1) m = "0" + m;
        if(s.size() == 1) s = "0" + s;
        cout << m + ":" + s << '\n';
    }
}