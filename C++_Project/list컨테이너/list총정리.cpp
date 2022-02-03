#include<stdio.h>
#include<list>
#include<iostream>
#include<algorithm>

using namespace std;

void stl(){
    list<char> list1;
    list<char>::iterator itor;
    itor = list1.begin();

    cout<< "--- c,b,a 값 삽입 ---" << endl;
    list1.push_back('c');
    list1.push_back('b');
    list1.push_back('a'); // list의 push_back()을 하면iterator는 넣은 값 다음 위치를 가리키고 있다.


    itor = list1.begin(); // 반복자 위치를 다시 맨 앞으로 바꿈
    while(itor != list1.end()){
        cout << *itor << endl;
        itor++;
    }
    
    itor = find(list1.begin(),list1.end(),'a');//find : 처음부터 끝까지 뒤져서 index를 던지고 있는지 확인
                                                //#include<algorithm>
                                                //반환값 : 반복자

    cout << "------find(a를 찾아 그 위치 앞에 d를 삽입한다.) ------" << endl;
    list1.insert(itor,'d'); // 찾아낸 값의 앞위치에 d를 집어넣기. 없으면 맨 뒤에 들어감

    for(itor= list1.begin(); itor != list1.end(); itor++){
        cout << *itor << endl;
    }

    //b삭제하기
    cout << "----remove b----"<<endl;
    itor = find(list1.begin(),list1.end(),'b');
    list1.erase(itor);

    itor = list1.begin();
    while(itor != list1.end()){
        printf("%c\n",*itor);
        itor++;
    }

    //해당 인덱스 위치에 값을 넣는 방법
    int i=0;
    int index = 2;
    cout << "----- 해당 index위치에 값 넣기 ----- " << endl;

    for(itor = list1.begin(); itor != list1.end(); itor++,i++){
        if(i == index) break;
    }
    list1.insert(itor,'f');

    itor = list1.begin();
    while(itor != list1.end()){
        cout << *itor << endl;
        itor++;
    }

}

int main(){
    stl();
}