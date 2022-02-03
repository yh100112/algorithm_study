#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){

    string key_to_find;
    map<string,string> lang_map = {{
        {"a","apple"},
        {"b","banana"},
        {"c","camal"}
    }};

    cout << "찾을 키값 : ";
    cin >> key_to_find;

    if(lang_map.find(key_to_find) == lang_map.end()){
        cout << "key없음" <<endl;
    }else{
        cout << "key : " << key_to_find << " value : " << lang_map[key_to_find] << endl;
    }


    return 0;
}