#include <iostream>
using namespace std;

int main(void){
    int a[10][10];
    fill(&**a,&**(a+sizeof(a)),10);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}