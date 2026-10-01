#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

string solution(int n, int m, int x, int y, int dr, int dc, int k) {
    string answer = "impossible";
    int r, c, nr, nc;
    string path, nd;
    queue<tuple<int,int,int,string>> q; 
    map<char, pair<int,int>> mp = {{'d',{1,0}},{'l',{0,-1}},{'r',{0,1}},{'u',{-1,0}}};
    q.push({x,y,0,""});
    while(!q.empty()){
        auto [r,c,d,path] = q.front(); q.pop();
        if(path.size()>k){
            break;
        }
        if(r==dr&&c==dc&&d==k){
            answer = path;
            break;
        }
        for(const auto& p:{'d','l','r','u'}){
            auto [pr, pc] = mp[p];
            nr = r+pr; nc = c+pc;
            if(0<nr&&nr<=n&&0<nc&&nc<=m&&((abs(nr-dr)+abs(nc-dc)+d+1)<=k)){
                q.push({nr,nc,d+1,path+p});
                break;
            }
        }
    }
    return answer;
}