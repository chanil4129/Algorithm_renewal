#include <stdio.h>

int main(void){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int j=a-i;j<a;j++){
            printf(" ");
        }
        for(int j=0;j<(a-i-1)*2+1;j++){
            printf("*");
        }
        printf("\n");
    }
}