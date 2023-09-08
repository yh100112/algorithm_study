#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> n(8);
	int check = 100;
	for(int i = 0; i < 8; i++){
		cin >> n[i];
	}
	for(int i = 1; i < 8; i++){
		if(n[i] > n[i-1]){
			if(check == 1){
				check = 2;
				break;
			}
			check = 0; // ascend
		}
		else{
			if(check == 0){
				check = 2;
				break;
			}
			check = 1; // descend
		}
	}
	if(check == 0)
		cout << "ascending";
	else if(check == 1)
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}