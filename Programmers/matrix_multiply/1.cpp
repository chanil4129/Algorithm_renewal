#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int a=0;
    vector<int> b;
    for(int store=0;store<arr1.size();store++){
        b.clear();
        for(int i=0;i<arr2[0].size();i++){
            a=0;
            for(int j=0;j<arr1[0].size();j++){
                a+=arr1[store][j]*arr2[j][i];
            }
            b.push_back(a);
        }
        answer.push_back(b);
    }
    return answer;
}