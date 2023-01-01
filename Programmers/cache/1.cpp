#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cachePage;
        
    for(int i=0;i<cities.size();i++){
        string city;
        int cachePageSize=cachePage.size();
        for(int a=0;a<cities[i].size();a++){
            city+=tolower(cities[i][a]);
        }
        if(cacheSize==0){
            answer+=5;
        }
        else if(cachePageSize<cacheSize){
            cachePage.remove(city);
            if(cachePageSize==cachePage.size()){//miss
                cachePage.push_back(city);
                answer+=5;
            }
            else{//hit
                cachePage.push_back(city);
                answer+=1;
            }
        }
        else{
            cachePage.remove(city);
            if(cachePage.size()!=cacheSize){//hit
                cachePage.push_back(city);
                answer+=1;
            }
            else{//miss
                cachePage.pop_front();
                cachePage.push_back(city);
                answer+=5;
            }
        }
    }
    
    return answer;
}