#include<iostream>
#include<deque>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
  int i,j;
  int T;
  cin >> T; // test case 개수

  for (i = 0; i < T; ++i) {
    string p;   // 수행할 함수
    int n;      // 배열에 들어있는 수의 개수
    string arr; // 배열에 들어있는 정수들

    cin >> p >> n >> arr;

    deque<int> dq;

    arr.erase(0,1);
    arr.erase(arr.length() - 1, 1);
    stringstream ss(arr);
    string token;
    while (getline(ss, token, ',')) {
      dq.push_back(stoi(token));
    }

    bool r_check = false;
    bool err_check = false;
    for (j = 0; j < p.length(); ++j) {
      string func_name = p.substr(j,1);
      if (func_name == "R") {
        if (r_check)
          r_check = false;
        else
          r_check = true;
      }
      else if (func_name == "D") {
        if (dq.empty()) {
          cout << "error";
          err_check = true;
          break;
        }
        if (r_check)
          dq.pop_back();
        else
          dq.pop_front();

        --n;
      }
    }
    
    if (!err_check) {
      for (j = 0; j < n; ++j) {
        if (j == 0) {
          cout << "[";
        }

        if (r_check) {
          cout << dq.back();
          dq.pop_back();
        }
        else {
          cout << dq.front();
          dq.pop_front();
        }

        if (j != n - 1)
          cout << ",";
        else if (j == n - 1)
          cout << "]";
      }
      cout << endl;
    }
  }
}