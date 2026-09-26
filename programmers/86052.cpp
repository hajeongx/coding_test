#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;
set<vector<int>> visited;
queue<tuple<int,int,int>> q;
vector<int> dr = {-1, 0, 1, 0}, dc = {0,1,0,-1};
map<char, int> sd = {{'S', 0}, {'L',-1}, {'R',1}};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int n = grid.size(), m = grid[0].size();
    int nr, nc, nd, r, c, d;
    int l;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++){
                if(!visited.count({i,j,k})){
                    l = 1;
                    q.push({i, j, k});
                    visited.insert({i,j,k});
                    while(!q.empty()){
                        auto [r,c,d] = q.front();
                        q.pop();
                        nd = (d+sd[grid[r][c]]+4)%4;
                        nr = (r+dr[nd]+n)%n;
                        nc = (c+dc[nd]+m)%m;
                        if(!visited.count({nr,nc,nd})){
                            l += 1;
                            q.push({nr,nc,nd});
                            visited.insert({nr,nc,nd});
                        }
                    }
                    answer.push_back(l);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}