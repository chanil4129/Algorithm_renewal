#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int score[1111];
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    int _max=0;
    for(int i=0;i<n;i++){
        if(_max<score[i])
            _max=score[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=score[i];
    }
    printf("%f",ans/(float)_max*100/n);
}