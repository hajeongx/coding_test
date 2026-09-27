#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int x, nx, d, cnt=0;
    vector<int> visited(n, 0);
    vector<vector<int>> adj(n);
    vector<int> res;
    queue<pair<int,int>> q;
    
    for(int i=0;i<edge.size();i++){
        adj[edge[i][0]-1].push_back(edge[i][1]-1);
        adj[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    visited[0] = 1;
    q.push({0, 0});
    while(!q.empty()){
        auto [x, d] = q.front();
        res.push_back(d);
        q.pop();
        for(const auto& nx: adj[x]){
            if(!visited[nx]){
                q.push({nx, d+1});
                visited[nx] = 1;
            }
        }
    }
    int k = res.size()-1;
    for(int i=k;i>=0;i--){
        if(res[i]==res[k]){
            cnt +=1;
        }
        else{
            break;
        }
    }
    
    return cnt;
}