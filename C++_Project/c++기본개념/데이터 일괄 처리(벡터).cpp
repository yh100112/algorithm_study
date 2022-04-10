#include<iostream>
#include<iomanip>
#include<ios>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

//기존의 데이터일괄처리.cpp에서 점수 각각을 기존의 합에 더한후 바로 버리는 대신,점수를 벡터에 저장하는 방식으로 다시 작성
//벡터 : 값의 집단이 있는 컨테이너이다. 각 벡터의 값은 모두 같은 타입. 벡터를 정의할 때마다 벡터가 담을 값의 타입을 지정해야 함.
//객체의 타입은 꺾쇠괄호를 사용해서 지정함  =>  vector<double> , vector<string>
//vector.push_back(x)   :   벡터의 마지막에 새 요소를 추가하는 작업(새 요소 = x) , 해당 인수를 벡터의 뒤쪽으로 넣으며 이때 벡터의 크기는 1씩 증가한다.
int main(){
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm,final;
    cin >> midterm >> final; 

    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";

    double x;
    vector<double> homework;


    while(cin >> x){ 
        homework.push_back(x);
    }

    /*size_type :   크기가 큰 벡터도 충분히 담을 수 있는 부호 없는 타입
      size()    :   벡터의 요소 개수를 나타내는 size_type값을 반환 , 벡터의 원소의 개수(벡터의 총 길이)를 알아낼 때 사용함. 문자열의 크기를 알아낼 때와 똑같음
    */
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if(size == 0){
        cout << endl;
        cout << "you must enter your grades. 다시 입력하세요." << endl;
        return 1;
    }
    
    cout << "정렬 전 : ";
    for(int i = 0; i < size; i++){
        cout << homework[i] << " ";
    }

    sort(homework.begin(),homework.end()); /*<algorithm> 헤더에 정의되어있음. 컨테이너가 담은 값들을 오름차순으로 정렬함.
                                            vector.begin() : 벡터의 첫번째 요소의 위치
                                            vector.end() : 벡터의 마지막 요소의 위치
                                            sort()함수는 정렬한 결과를 담으려고 새 컨테이너를 만들지 않는다. 단지 컨테이너의 요소값들을 정렬시킨다.
                                            */
    cout << endl;
    cout << "정렬 후 : ";
    for(int i = 0; i < size; i++){
        cout << homework[i] << " ";
    }
    cout << endl;

    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];



    //출력결과가 소수점 첫번재 자리(ex 88.3)이런 형태로 출력되게 하기 위해 setprecision(3)을 사용
    //precision을 호출하면 스트림이 부동 소수점 표현에 사용하는 정밀도를 알려줌. precision(3)을 이용해서도 정밀도를 바꿀 수 있지만 이렇게 하면 나중에 프로그램에서 바꾼 정밀도 때문에 발생하는 문제가 있는데, 이걸 최소화하기 위해
    //setprecision을 사용하는 습관을 들이자!
    streamsize prec = cout.precision(); 
    cout << "Your final grade is " << setprecision(3)
        <<0.2 * midterm + 0.4 * final + 0.4 * median
        << setprecision(prec) << endl;      


    return 0;
}














