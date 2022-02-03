#include<string.h>
#include<stdio.h>
 
int main(void)
{
    char src[] = "BlockDMask";
    char dest1[] = "abcdefghijklmnop";
    char dest2[] = "abcdefghijklmnop";

    // 메모리 복사1 : src 길이만큼만 복사
    memcpy(dest1, src, sizeof(char) * 10);

    // 메모리 복사2 : src 길이 + 1 만큼 복사
    memcpy(dest2, src, sizeof(char) * 10 + 1);

    // source
    printf("src  : %s\n", src);
    
    // destination
    printf("dest1 : %s\n", dest1);
    printf("dest2 : %s\n", dest2);

    printf("%d  %d\n",sizeof(dest1),sizeof(dest2));

    for(int i=0;i < 16; i++){
      printf("%c",dest2[i]);
    }

    return 0;
}

