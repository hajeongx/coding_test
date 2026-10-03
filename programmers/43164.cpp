#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<vector<string>>& tickets, vector<int>& visited, vector<string>& path) {
    if (path.size() == tickets.size() + 1) {
        return true;
    }
    string start = path.back();
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == start) {
            visited[i] = 1;
            path.push_back(tickets[i][1]);
            if (dfs(tickets, visited, path)) {
                return true;
            }
            visited[i] = 0;
            path.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<int> visited(tickets.size(), 0);
    vector<string> path = {"ICN"};
    dfs(tickets, visited, path);

    return path;
}