#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

const char* malloc_error = "malloc_error";

class String{
private:
  char* str;
public:
  String();
  String(const char* b);
  String(const String& obj);
  virtual ~String();
  int find(const char* b);
  String substr(int begin, int end) const;


  int size() const{
    return strlen(str);
  }
  char* contents() const {
    return str;
  }

  char operator[] (int idx);
  String& operator= (const String& obj);
  String operator+ (const String& obj) const;
  String& operator+= (const String& obj);

  bool operator== (const String& obj) const;
  bool operator!= (const String& obj) const;
  bool operator<= (const String& obj) const;
  bool operator>= (const String& obj) const;
  bool operator< (const String& obj) const;
  bool operator> (const String& obj) const;

};

bool String::operator< (const String& obj) const{
  if(strcmp(this->contents(),obj.contents()) < 0){
    return true;
  }
  return false;
}

bool String::operator> (const String& obj) const{
  if(strcmp(this->contents(),obj.contents()) > 0){
    return true;
  }
  return false;
}

bool String::operator<= (const String& obj) const{
  if(strcmp(this->contents(),obj.contents()) <= 0){
    return true;
  }
  return false;
}

bool String::operator>= (const String& obj) const{
  if(strcmp(this->contents(),obj.contents()) >= 0){
    return true;
  }
  return false;
}

bool String::operator!=(const String& obj) const{
  if(strcmp(this->contents(),obj.contents()) == 0){
    return false;
  }
  return true;  
}

bool String::operator==(const String& obj) const {
  if(strcmp(this->contents(),obj.contents()) == 0){
    return true;
  }
  return false;
}



char String::operator[](int idx){
  const char* error_name = "invalid";
  if((idx >= size()) || (idx < 0)){
    throw error_name;
  }
  return str[idx];
}

//a객체에 기존 char*를 해제하고 b객체와 똑같은 문자열을 만들어 복사할 것 (a = b)
String& String::operator=(const String& obj){
  free(str);
  int new_str_length = obj.size() + 1;
  str = (char*)malloc(sizeof(char) * new_str_length);
  if(str == NULL) throw malloc_error;

  for(int i = 0;i < new_str_length; i++){
    str[i] = obj.str[i];
  }

  return *this;
}


//앞 객체의 문자열과 뒤 객체의 문자열을 덧붙일 것
String& String::operator+=(const String& obj){
  int new_str_length = this->size() + obj.size() + 1;
  char* new_str = (char*)malloc(sizeof(char*) * new_str_length);
  if(new_str == NULL) throw malloc_error;

  for(int i = 0; i < this->size(); i++){
    new_str[i] = str[i];
  }
  for(int i = 0;i < obj.size(); i++){
    new_str[i+this->size()] = obj.str[i];
  }
  new_str[new_str_length] = '\0';
  
  char* temp = str;
  str = new_str; // 문자열은 어차피 주소값이므로 그냥 기존의 str의 시작주소에 new_str의 시작주소를 넣은 것뿐이다.
  free(temp); // 그 후 기존의 str의 시작주소를 해제해준 것이다.

  return *this;
}

//앞 객체의 문자열과 뒤 객체의 문자열을 붙인 새로운 객체 반환
String String::operator+(const String& obj) const{
  int new_str_length = this->size() + obj.size() + 1;
  char* new_str = (char*)malloc(sizeof(char*) * new_str_length);
  if(new_str == NULL) throw malloc_error;
  

  for(int i = 0; i < this->size(); i++){
    new_str[i] = str[i];
  }
  for(int i = 0;i < obj.size(); i++){
    new_str[i+this->size()] = obj.str[i];
  }
  new_str[new_str_length] = '\0';
  String new_obj(new_str);

  free(new_str);
  return new_obj;
}

String::String(const char* b){
  int str_length = strlen(b);
  str = (char*)malloc(sizeof(char) * (str_length+1));
  if(str == NULL) throw malloc_error;

  for(int i = 0;i < str_length; i++){
    str[i] = b[i];
  }
}

String::String(){
  str = (char*)malloc(sizeof(char));
  if(str == NULL) throw malloc_error;
  str[0] = '\0';
}


String::String(const String& obj){
  int str_length = strlen(obj.str);
  str = (char*)malloc(sizeof(char) *(str_length + 1));
  if(str == NULL) throw malloc_error;
  strcpy(str,obj.str);
  str[str_length] = '\0';
}

String::~String(){
  free(str);
}

int String::find(const char* b){  
  char* find_str = strstr(str,b);
  if(find_str == NULL) return -1;

  return (find_str - str);

}

String String::substr(int begin, int end) const {
  if(begin < 0){
    begin = 0;
  }

  if(end > size()){
    end = size() - 1;
  }

  int new_str_length = end-begin+1;
  char* new_str = (char*)malloc(sizeof(char) * (new_str_length + 1));
  if(new_str == NULL) throw malloc_error;
  for(int i = 0;i < new_str_length; i++){
    new_str[i] = str[begin];
    begin += 1; 
  }
  new_str[new_str_length] = '\0';
  String new_obj(new_str);

  free(new_str);
  return new_obj;
}

int main(){
  
  String str("abc");

  try{
    fprintf(stderr,"%c\n",str[1]);
    fprintf(stderr,"%c\n",str[5]);
  }catch(const char* e){
    fprintf(stderr,"%s\n",e);
  }

  String s("apple");
  String a("banana");

  s = a;
  printf("%s\n",s.contents());
  printf("%c\n",s[2]);
  printf("%d\n",s.find("a"));


  s += a;
  printf("%s\n",s.contents());
  printf("%d\n",s.size());
  
  s = s + a;
  printf("%s\n",s.contents());

  String p = s.substr(1,3).contents();
  printf("%s\n",p.contents());
  
}