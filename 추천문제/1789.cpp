#include<bits/stdc++.h>
using namespace std;
long long s;

int main() {
  cin >> s;

  long long sum = 0;
  long long temp = 0;
  for (int i = 1; i <= 1000000; i++) {
    sum += i;
    if (sum >= s) {
      temp = i;
      break;
    }
  }
  if (sum > s) temp--;
  cout << temp << "\n";
}