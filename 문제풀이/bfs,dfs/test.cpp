#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> s = {1,2,3,4};
	vector<int> temp = {0,0,1,1};

	do {
		for (int i = 0; i < s.size(); ++i)
			if (temp[i] == 1)
				cout << s[i] << ' ';
		cout << endl;
	} while (next_permutation(temp.begin(), temp.end()));
}
/*
12
13
14
23
24
34
*/