#include<bits/stdc++.h>
using namespace std;

void split(string a, vector<int>& v) {
	stringstream ss;
	string word;
	ss.str(a);
	while(getline(ss, word, ':')) { // stringstream ss를 ":"를 기준으로 나눈다.
		v.push_back(stoi(word));
	}
}