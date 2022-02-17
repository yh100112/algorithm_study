#include <string>
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include <vector>

using namespace std;

//°°Àº »ö±ò ¹«Á¶°Ç ¿«±â
int solution(int n, vector<int> colors) {
  int max = 0;
  int max_test = 0;
  int max_color = 0;
  int color = 0;
  int sum = 0;


  for(int i = 0; i < n; i++){
    if(color == 0){
      color = colors[i];
      max = count(colors.begin(),colors.end(),color);
      max_color = color;
    }else{
      if(color != colors[i]){
        color = colors[i];
        max_test = count(colors.begin(),colors.end(),color);
        if(max < max_test){
          max = max_test;
          max_color = color;
        }
      }
    }
  } // ÃÖ´ë °¹¼ö¿Í ±× ¶§ÀÇ °ª Ã£¾Æ³¿ : max,max_color

  cout << "max, max_color : " << max << " " << max_color << endl;
  sum += max * max;

  colors.erase(remove(colors.begin(), colors.end(), max_color), colors.end());


  color = 0;
  int cnt = 0;

  for(int i = 0; i < colors.size(); i++){
    if(color == 0){
      color = colors[i];
      cnt++;
    }else{
      if(color == colors[i]){
        cnt++;
      }else{
        sum += (cnt * cnt);
        color = colors[i];
        cnt = 1;
      }
    }
    if(i == colors.size() - 1){
      sum += (cnt * cnt);
    }
  }

  return sum;
}

int main(){
  vector<int> a = {1,2,3,4,5,5,5,5,5,1};
  int answer = solution(10,a);
  printf("%d\n",answer);
}