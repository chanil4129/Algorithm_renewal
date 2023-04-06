#include <iostream>
using namespace std;

int main(void){
    int n;
    int arr[1234567];
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int _max=-1000000;
    int _min=1000000;
    for(int i=0;i<n;i++){
        if(_max<arr[i])
            _max=arr[i];
        if(_min>arr[i])
            _min=arr[i];
    }

    cout<<_min<<" "<<_max;
}