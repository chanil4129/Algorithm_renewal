#include <iostream>
using namespace std;

int main(){
    int n;
    int d[43]={0,};
    for(int i=0;i<10;i++){
        cin>>n;
        d[n%42]++;
    }
    int ans=0;
    for(int i=0;i<42;i++){
        if(d[i]>0)
            ans++;
    }
    cout<<ans;

}