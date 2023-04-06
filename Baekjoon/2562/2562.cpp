#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=0;i<9;i++){
        cin>>arr[i];
    }
    int _max=arr[0];
    int _maxIdx=1;
    for(int i=1;i<9;i++){
        if(_max<arr[i]){
            _max=arr[i];   
            _maxIdx=i+1;
        }
    }
    cout<<_max<<"\n"<<_maxIdx;
}