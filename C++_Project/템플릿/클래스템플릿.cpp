#include<iostream>
using namespace std;

template<typename T>
class Data{
private:
  T data;
public:
  Data(T d);
  void SetData(T d);
  T GetData();
};

//외부 클래스 정의
template<typename T>
Data<T>::Data(T d){
  data = d;
}

// 외부 클래스 정의
template<typename T>
void Data<T>::SetData(T d){
  data = d;
}


//외부 클래스 정의
template<typename T>
T Data<T>::GetData(){
  return data;
}

int main(){
  class Data<int> d1(0);
  d1.SetData(10);

  class Data<char> d2('a');

  cout << d1.GetData() << endl;
  cout << d2.GetData() << endl;

  return 0;
}
//클래스 템플릿을 만들 때는 명시적으로 타입을 꼭 써줘야 한다.