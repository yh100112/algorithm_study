#include<bits/stdc++.h>
using namespace std;


// ���� § �ڵ�
// int arr[10];

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   string N;
//   cin >> N;

//   for(int i = 0; i < N.length(); i++){
//     arr[N[i] - '0']++;
//   }

//   int max = 0;
//   int max_num = -1;
//   for(int i = 0; i < 10; i++){
//     if(max < arr[i]){
//       max = arr[i];
//       max_num = i;
//     } 
//   }

//   if(max_num == 9 || max_num == 6){
//     if(max_num == 9){
//       max += arr[6];  
//     }else{
//       max += arr[9];
//     }

//     if(max % 2 == 0){
//       max = max / 2;
//     }else{
//       max = max / 2 + 1;
//     }
//   }

//   for(int i = 0; i < 10; i++){
//     if(i != 6 && i != 9){
//       if(max <= arr[i]){
//         max = arr[i];
//       }
//     }
//   }

//   cout << max;
// }


//��ŷ�� �ڵ�
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // ans = 1�� �����ν� N = 0�� ���� ���� ����ó���� �ڿ������� ��������
  int N, a[10] = {}, ans = 1;
  cin >> N;

  // �ڸ��� ����
  while(N){
    a[N % 10]++;
    N /= 10;
  }

  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }

  //(a[6] + a[9])/2 �� �ø��� ����  6,9�� ���� �ʿ��� ��Ʈ�� ���̹Ƿ� (a[6] + a[9] + 1)/2 �� ���
  ans = max(ans, (a[6] + a[9] + 1)/2);
  cout << ans;
}