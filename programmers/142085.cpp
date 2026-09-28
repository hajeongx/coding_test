#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int>> minpq;
    int idx = 0, total = 0;
    while(idx < enemy.size()){
        if(minpq.size()<k){
            minpq.push(enemy[idx]);
        }
        else{
            if(minpq.top() < enemy[idx] && minpq.top()+total <= n){
                total += minpq.top();
                minpq.pop();
                minpq.push(enemy[idx]);
            } else if(minpq.top() >= enemy[idx] && enemy[idx]+total <= n){
                total += enemy[idx];
            } else{
                break;
            }
        }
        idx += 1;
    }
    return idx;
}