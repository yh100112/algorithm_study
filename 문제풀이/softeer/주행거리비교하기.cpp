#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n,m;
	cin >> n >> m;
	if(n > m)
		cout << "A";
	else if (n < m)
		cout << "B";
	else
		cout << "same";
	return 0;
}
