// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//   int n; 
//   vector<string> v;
//   cin >> n;
//   for(int i = 0; i < n; i++){
//     int cnt;
//     string in;
//     cin >> cnt >> in;
//     string new_ans = "";
//     for(int j = 0; j < in.length(); j++){
//       string a = "";
//       for(int k = 0; k < cnt; k++)
//         a += in[j];
//       new_ans += a;
//     }
//     v.push_back(new_ans);
//   }

//   for(auto& ss: v)
//     cout << ss << "\n";
// }
#include <iostream>
#include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for(int i = 0;i < t;i++)
  {
    int r;
    string p;
    cin >> r;
    cin >> p;
    for(int j = 0;j < p.length();j++)
    {
      for(int k = 0;k < r;k++)
      {
        cout << p[j];
      }
    }
    cout << endl;
  }
  return 0;
}