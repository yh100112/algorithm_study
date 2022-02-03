#include <iostream>
#include <string>
using namespace std;

class Friend1 {
private :
    string name;
    friend void set_name(Friend1&, string); //set_name()함수는 친구니까 내 private 변수에 접근 허용!!
};

void set_name(Friend1& f, string s) {
    f.name = s;
    cout << f.name << "\n";
}

int main(void) {
    Friend1 f1;
    set_name(f1, "열코");
    return 0;
}

