#include <string>
#include <vector>

using namespace std;

    
void dfs(int now, int& n, vector<int>& visited, vector<vector<int>>& computers) {
    visited[now] = 1;
    for(int i=0; i<n; i++){
        if(computers[now][i] && !visited[i]){
            dfs(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j] && !visited[j]){
                dfs(j, n, visited, computers);
                answer +=1;
            }
        }
    }
    
    return answer;
}