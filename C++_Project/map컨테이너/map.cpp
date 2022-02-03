#include<map>
#include<iostream>

using namespace std;

int main(){
    map<string,int> m;

    cout <<"**********insert**********"<<endl;
    //1
    m.insert(pair<string,int>("marin",40));

    //2
    m.insert(make_pair("scv",60));

    //3
    m["firebat"] = 50;

    cout <<"**********iterate**********"<<endl;
    //1
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    //2
    for(pair<string,int> atom : m){
        cout << atom.first << " " << atom.second << endl;
    }

    cout << "**********find**********" << endl;
    //1
    cout <<m.find("scv")->first << " " << m.find("scv")->second << endl;
    
    //2
    cout <<"scv" << " "<<m["scv"] << endl;

    cout << "**********erase**********" << endl;
    //1
    m.erase("scv");
    
    //2
    m.erase(m.find("firebat"));
    for(pair<string,int> atom : m){
        cout << atom.first << " " << atom.second << endl;
    }

    cout << "**********size**********" << endl;
    cout << m.empty() << endl;

    return 0;
}