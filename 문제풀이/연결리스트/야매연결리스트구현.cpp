#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// addr�� �迭�󿡼� ���� ���� �ִ� ���� ����������� �ǹ�
// ���� ���� 13�� 2�����̰� 13�ڿ� 20�� �߰��ϰ� �ʹٸ� insert(2, 20)�� ȣ���ؾ� ��
// 13�� ����� �ʹٸ� erase(2)�� ȣ���ؾ� �� 2�� �ǹ��ϴ� ���� ���� ����Ʈ �󿡼�
// 2��° ���Ҷ�� ���� �ƴ϶� �ش� ������ �ּҰ� 2������� ���� �򰥸��� �ȵ�
void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = 
}

void erase(int addr){

}

void traverse(){
  int cur = nxt[0]; // cur�� ������ ���� ����ִ� �ּҰ��� ��
  while(cur != -1){ // �� ����ϴٰ� cur�� -1�� ���� ���� ������ while�� Ż��
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  // erase_test();
}