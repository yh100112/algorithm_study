#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct S_String{
  struct S_String* this;
  char* str;

  char* (*getStr)(struct S_String* this);

  int (*findString)(struct S_String* this, struct S_String* b);
  int (*assignString)(struct S_String* this, struct S_String* b);
  int (*concatString)(struct S_String* this, struct S_String* b);
  char (*charAt)(struct S_String* this, int b);
  int (*isStringSame)(struct S_String* this, struct S_String* b);
  int (*isStringDifferent)(struct S_String* this, struct S_String* b);
  int (*compareString) (struct S_String* this, struct S_String* b);

}String_S;

//생성자,소멸자
String_S* newString(const char* b);  //문자열 입력 생성자
String_S* copyString(String_S* b);   // 객체 복사 생성자 
String_S* concatNewString(String_S* this,String_S* b);  // this뒤에 b를 붙여 생성한 새로운 객체 반환
String_S* subString(String_S* this,int begin, int end); //시작위치부터 끝 위치까지 자른 새로운 문자열 객체 반환
void deleteString(String_S* this);

//함수
int assignString(String_S* this,String_S* b); 
int concatString(String_S* this,String_S* b);
char charAt(String_S* this, int b); 
int isStringSame(String_S* this, String_S* b); 
int isStringDifferent(String_S* this,String_S* b); 
int compareString(String_S* this, String_S* b); 
int findString(String_S* this, String_S* b); 

char* getStr(String_S* this); //현재 str값 반환


int main(){
  /* newString, concatString, assignString, deleteString */
  String_S* a = newString("hello");
  String_S* b = newString("banana");
  a->concatString(a,b);
  printf("바꾸기 전 a : %s\n",a->getStr(a));

  if(a->assignString(a,b) == 0){
    printf("복사 성공!\n");
    printf("바꾼 후 a : %s\n",a->getStr(a)); // a를 b로 바꾼 후 str출력
  }else{
    printf("복사 실패!\n");
  }
  deleteString(a);
  deleteString(b);
  printf("--------------------------------\n");

  /* copyString, findString, charAt, isStringSame, isStringDifferent, compareString */
  String_S* aa = newString("pineapple");
  String_S* bb = newString("apple");
  String_S* copy_aa = copyString(aa);
  printf("copy_aa : %s\n",copy_aa->getStr(copy_aa));
  printf("copy_aa에서 findString으로 'apple' 문자열 위치 찾기 -> %d\n",copy_aa->findString(copy_aa,bb));
  printf("copy_aa에서 문자열의  인덱스 %d의 문자 반환 : %c\n",3,copy_aa->charAt(copy_aa,3));

  printf("isStringsame : %d\n",aa->isStringSame(aa,bb)); // 같으면 1 같지 않으면 0
  printf("isStringsame : %d\n",aa->isStringSame(aa,copy_aa)); // 같으면 1 같지 않으면 0
  printf("isStringDifferent : %d\n",aa->isStringDifferent(aa,bb)); // 같으면 0 같지 않으면 1
  printf("isStringDifferent : %d\n",aa->isStringDifferent(aa,copy_aa)); // 같으면 0 같지 않으면 1
  printf("compareString : %d\n",aa->compareString(aa,copy_aa)); // 0나옴

  deleteString(aa);
  deleteString(copy_aa);
  deleteString(bb);
  printf("--------------------------------\n");
  
  /* concatNewString, subString */
  String_S* str1 = newString("tiger");
  String_S* str2 = newString("spider");
  String_S* new = concatNewString(str1,str2);
  printf("new : %s\n",new->getStr(new));

  String_S* sub = subString(new,1,5);
  printf("sub : %s\n",sub->getStr(sub));

  deleteString(str1); 
  deleteString(str2);
  deleteString(new);
  deleteString(sub);

}

String_S* subString(String_S* this, int begin, int end){
  int curr_length = strlen(this->str);
  if(begin < 0) {
    begin = 0;
  }
  if(end > curr_length - 1){
    end = curr_length - 1;
  } 
  
  int new_str_length = end - begin + 1;

  String_S* obj = (String_S*)malloc(sizeof(String_S));
  if(obj){
    if((obj->str = (char*)calloc(new_str_length + 1,sizeof(char))) == NULL){
      free(obj);
      obj = NULL; // 혹시모르니 null넣어줌
    }
    obj->str[0] = 0;
  }
  for(int i = 0;i < new_str_length; i++){
    obj->str[i] = this->str[begin];
    begin += 1;
  }
  obj->str[new_str_length] = '\0';

  obj->this = obj; // this 구현
  obj->getStr = getStr;
  obj->findString = findString;
  obj->assignString = assignString;
  obj->concatString = concatString;
  obj->charAt = charAt;
  obj->isStringSame = isStringSame;
  obj->isStringDifferent = isStringDifferent;
  obj->compareString = compareString;
  return obj;
}


char* getStr(String_S* this){
  return this->str;
}

int compareString(String_S* this, String_S* b){
  return strcmp(this->str,b->str);
}

int isStringDifferent(String_S* this, String_S* b){
  if(strcmp(this->str,b->str) == 0){
    return 0;
  }
  return 1;  
}

int isStringSame(String_S* this, String_S* b){
  if(strcmp(this->str,b->str) == 0){
    return 1;
  }
  return 0;
}

char charAt(String_S* this, int b){
  return this->str[b];
}

int assignString(String_S* this, String_S* b){
  free(this->str);

  if((this->str = (char*)malloc(sizeof(strlen(b->str) + 1))) == NULL){
    return -1; /*복사할 문자열이 null이면 실패*/
  };
  strcpy(this->str,b->str);
  return 0;
}

int concatString(String_S* this, String_S* b){
  int origin_length  = strlen(this->str); 
  int new_str_length = strlen(this->str) + strlen(b->str) + 1; 

  // realloc(this->str,new_str_length); 잘못된 방법

  char* new = realloc(this->str,new_str_length);
  if(new != NULL){
    this->str = new;
  }

  for(int i = origin_length;i < new_str_length-1; i++){
    this->str[i] = b->str[i - origin_length];
  }
  this->str[new_str_length - 1] = '\0';

  return 0;
}

int findString(String_S* this, String_S* b){
  char* i = strstr(this->str,b->str);
  if(i){
    return (i - this->str);
  }
  return -1;
}



String_S* copyString(String_S* b){
  String_S* obj = (String_S*)malloc(sizeof(String_S));
  
  if(obj){
    if((obj->str = (char*)calloc(strlen(b->str) + 1,sizeof(char))) == NULL){
      free(obj);
      obj = NULL; // 혹시모르니 null넣어줌
    }
    obj->str[0] = 0;
  }
  strcpy(obj->str,b->str); //받은 객체의 문자열을 str에 복사


  obj->this = obj; // this 구현
  obj->getStr = getStr;
  obj->findString = findString;
  obj->assignString = assignString;
  obj->concatString = concatString;
  obj->charAt = charAt;
  obj->isStringSame = isStringSame;
  obj->isStringDifferent = isStringDifferent;
  obj->compareString = compareString;
  return obj;
}

String_S* newString(const char* b){
  String_S* obj = (String_S*)malloc(sizeof(String_S));

  if(obj){
    if((obj->str = (char*)calloc(strlen(b) + 1,sizeof(char))) == NULL){
      free(obj);
      obj = NULL;
    }
    obj->str[0] = 0; /*여기서 문자열 초기화*/
  }
  strcpy(obj->str,b);

  obj->this = obj; // this 구현
  obj->getStr = getStr;
  obj->findString = findString;
  obj->assignString = assignString;
  obj->concatString = concatString;
  obj->charAt = charAt;
  obj->isStringSame = isStringSame;
  obj->isStringDifferent = isStringDifferent;
  obj->compareString = compareString;
  return obj;
}

String_S* concatNewString(String_S* this, String_S* b){
  int new_str_length = strlen(this->str) + strlen(b->str) + 1;
  String_S* obj = (String_S*)malloc(sizeof(String_S));
  if(obj){
    if((obj->str = (char*)calloc(new_str_length,sizeof(char))) == NULL){
      free(obj);
      obj = NULL; 
    }
    obj->str[0] = 0;
  }

  for(int i = 0; i < strlen(this->str); i++){
    obj->str[i] = this->str[i];
  }

  for(int i = strlen(this->str);i < new_str_length-1; i++){
    obj->str[i] = b->str[i - strlen(this->str)];
  }
  obj->str[new_str_length - 1] = '\0';

  obj->this = obj; // this 구현
  obj->getStr = getStr;
  obj->findString = findString;
  obj->assignString = assignString;
  obj->concatString = concatString;
  obj->charAt = charAt;
  obj->isStringSame = isStringSame;
  obj->isStringDifferent = isStringDifferent;
  obj->compareString = compareString;  
  return obj;
}

void deleteString(String_S* this){
  if(this->str) {
    free(this->str);
    this->str = NULL;
  }
  free(this);
}




