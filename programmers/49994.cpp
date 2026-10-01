#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<char, pair<int,int>> d = {{'U',{-1,0}}, {'D',{1,0}}, {'R',{0,1}}, {'L',{0,-1}}};
set<vector<int>> visited;

int solution(string dirs) {
    int answer = 0, r=0, c=0, nr, nc, dr, dc;
    for(const auto& dir:dirs){
        auto [dr, dc] = d[dir];
        nr = r+dr; nc = c+dc;
        if(-5<=nr&&nr<=5&&-5<=nc&&nc<=5){
            if(!visited.count({r,c,nr,nc})){
                visited.insert({r,c,nr,nc});
                visited.insert({nr,nc,r,c});
                answer += 1;
            }
            r = nr; c = nc;
        }
    }
    return answer;
}