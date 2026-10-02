#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int sheep, int wolves, int ans, vector<int>& visited, vector<vector<int>>& edges, vector<int>& info) {
    if (sheep <= wolves)
        return ans;
    ans = max(ans, sheep);
    for (const auto& edge : edges) {
        int x = edge[0];
        int nx = edge[1];
        if (visited[x] && !visited[nx]) {
            visited[nx] = 1;
            ans = dfs(sheep + int(info[nx] == 0),wolves + int(info[nx] == 1),
                ans, visited, edges, info);
            visited[nx] = 0;
        }
    }
    return ans;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<int> visited(n, 0);
    visited[0] = 1;
    int ans = 1;
    int sheep = 1;
    int wolves = 0;

    ans = dfs(sheep, wolves, ans, visited, edges, info);

    return ans;
}