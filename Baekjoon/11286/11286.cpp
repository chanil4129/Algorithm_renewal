#include <iostream>
#include <queue>
using namespace std;

int N;

int main(void){

    int x;
    priority_queue<int> pq; //positive priority queue
    priority_queue<int> nq; //negative priority queue
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x>0) pq.push(-x); //오름차순
        else if(x<0) nq.push(x); //내림차순
        else if(pq.empty()&&nq.empty()&&x==0) cout<<0<<"\n"; //비어있는데 0을 입력받으면 0출력
        else { //우선순위 큐에 값이 있으며, 0을 입력받으면
            if(pq.empty()){ //pq만 비어있으면
                cout<<nq.top()<<"\n"; 
                nq.pop(); //pq에서 꺼내기
            }
            else if(nq.empty()){ //nq만 비어있으면
                cout<<-pq.top()<<"\n"; 
                pq.pop(); //nq에서 꺼내기
            }
            else{ //pq,nq 둘다 값이 있다면 절댓값이 가장 작은 값을 출력. 중복이 있다면 가장 작은 수 출력.
                if(pq.top()>nq.top()){
                    cout<<-pq.top()<<"\n"; 
                    pq.pop(); //pq에서 꺼내기
                }
                else{
                    cout<<nq.top()<<"\n"; 
                    nq.pop();//nq에서 꺼내기
                }
            }
        }
    }
}

//https://www.acmicpc.net/problem/11286