#include<bits/stdc++.h>
using namespace std;
map<string, vector<int>> m;

void makeInfo(string info[], string ret, int idx) {
    if (idx == 4) {
        int score = stoi(info[4]);
        m[ret].push_back(score);
        return;
    }
    makeInfo(info, ret + "-", idx + 1);
    makeInfo(info, ret + info[idx], idx + 1);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> ret;
    string s[5], str;
    
    for (int i = 0; i < info.size(); i++) {
        istringstream ss(info[i]);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
        makeInfo(s, "", 0);
    }
    
    for (auto& p : m)
        sort(p.second.begin(), p.second.end());
    
    for (int i = 0; i < query.size(); i++) {
        istringstream ss(query[i]);
        ss >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;
        int score = stoi(str);
        vector<int> v = m[s[0] + s[1] + s[2] + s[3]];
        int idx = v.size();
        int lo = 0;
        int hi = v.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid] >= score) {
                idx = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        ret.push_back(v.size() - idx);
    }
    return ret;
}

