#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cachePage;
        
    for(string &s : cities){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        auto city=find(cachePage.begin(),cachePage.end(),s);
        if(city != cachePage.end()){
            cachePage.remove(s);
            cachePage.push_back(s);
            answer+=1;
        }
        else{
            cachePage.push_back(s);
            if(cachePage.size()>cacheSize)
                cachePage.pop_front();
            answer+=5;
        }
    }
    
    return answer;
}