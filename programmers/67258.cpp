#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int s = 0, l = 100000;
    unordered_map<string,int> visited;
    unordered_set<string> sg(gems.begin(), gems.end());
    int t = sg.size();
    for(int e=0;e<gems.size();e++){
        if(visited.count(gems[e])){
            visited[gems[e]] += 1;
        }
        else{
            visited[gems[e]] = 1;
        }
        while(visited.size()==t){
            if(e-s < l){
                l = e-s;
                answer = {s+1,e+1};
            }
            if(visited[gems[s]]==1){
                visited.erase(gems[s]);
            }
            else{
                visited[gems[s]]-=1;
            }
            s += 1;
        }
    }
    
    return answer;
}