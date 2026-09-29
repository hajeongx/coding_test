#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> dr = {-1,-1,0,1,1,1,0,-1};
vector<int> dc = {0,1,1,1,0,-1,-1,-1};
set<pair<int,int>> visited_p;
set<tuple<int,int,int>> visited_d;

int solution(vector<int> arrows) {
    int answer = 0, r=0,c=0,nr,nc,nd;
    visited_p.insert({r,c});
    
    for(int i=0;i<arrows.size();i++){
        nd = arrows[i];
        for(int j=0;j<2;j++){
            nr = r+dr[nd];
            nc = c+dc[nd];
            if(visited_p.count({nr,nc}) && !visited_d.count({nr,nc,nd})){
                answer += 1;
            }
            visited_p.insert({nr,nc});
            visited_d.insert({nr,nc,nd});
            visited_d.insert({r,c,(nd+4)%8});
            r = nr;
            c = nc;
        }
    }
    return answer;
}