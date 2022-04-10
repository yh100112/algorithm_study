#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> waiting)
{
    vector<int> answer;
    for(int i = 0; i < waiting.size(); i++){
        if(find(answer.begin(),answer.end(),waiting[i]) == answer.end()){
            answer.push_back(waiting[i]);
        }
    } 
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return answer;
}

int main(){
  vector<int> waiting = {5,4,4,3,2};
  solution(waiting);
}