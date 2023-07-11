#include <bits/stdc++.h>
using namespace std;

int N;
int d[130][130];
int white,blue;

void f(int n,int m,int size){
    if(size==0){
        return;
    }
    bool is_blue=true;
    bool is_white=true;
    for(int i=n;i<n+size;i++){
        for(int j=m;j<m+size;j++){
            if(d[i][j]==0){
                is_blue=false;
            }
            if(d[i][j]==1){
                is_white=false;
            }
        }
    }
    if(is_blue){
        blue++;
        return;
    }
    if(is_white){
        white++;
        return;
    }
    int half=size/2;
    f(n,m,half);
    f(n+half,m,half);
    f(n,m+half,half);
    f(n+half,m+half,half);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>d[i][j];
        }
    }
    f(0,0,N);
    cout<<white<<"\n"<<blue<<"\n";
}