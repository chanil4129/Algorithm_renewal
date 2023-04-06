#include <iostream>
using namespace std;

int main(void) {
    int c; cin>>c;
    int n;
    int d[1111];
    while(c--){
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>d[i];
            sum+=d[i];
        }
        float avg=sum/(float)n;
        int win=0;
        for(int i=0;i<n;i++){
            if(d[i]>avg)
                win++;
        }
        printf("%.3f%%\n",win/(float)n*100);
    }
}
