from copy import deepcopy

def solution(cost, hint):
    ans = 1e9
    n = len(cost)
    a = [0]*n
    
    def dfs(stage, buy, total, A):
        nonlocal ans
        if stage >= n:
            ans = min(ans, total)
            return
        if buy:
            total += hint[stage][0]
            for i in hint[stage][1:]:
                A[i-1] += 1
        total += cost[stage][min(A[stage],n-1)]
        if stage < n-2:
            dfs(stage+1, 1, total, deepcopy(A))
        dfs(stage+1, 0, total, deepcopy(A))
            
    dfs(0, 1, 0, deepcopy(a))
    dfs(0, 0, 0, deepcopy(a))
    
    return ans