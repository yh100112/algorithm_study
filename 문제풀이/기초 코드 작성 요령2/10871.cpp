#include<iostream>
using namespace std;

//���� § ��
// int main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   int x,y;
//   cin >> x >> y;
//   int a[x];
//   for(int i = 0; i < x; i++){
//     cin >> a[i];
//   }

//   for(int i = 0; i < x; i++){
//     if(a[i] < y){
//       cout << a[i] << " ";
//     }
//   }
// }

//��ŷ���� § ��
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x,t;
  cin >> n >> x;
  while(n--){
    cin >> t;
    if(t < x) cout << t << " ";
  }
}

/*
sync,cin.tie�� ���� ���� �Ƚ��� �� �¶����������� ä���� �ӵ��� 0ms, 4ms�� 
sync,cin.tie�� ���� ���� �� ������.
*/