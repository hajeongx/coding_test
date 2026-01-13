from collections import deque

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
dc = [-1, 0, 1]

q = deque()
res = []

for i in range(m):
    q.append((0,i,2,0))
    while q:
        r, c, d, total = q.popleft()
        total += arr[r][c]
        for k in dc:
            nc = c + k
            if d != k and 0 <= nc < m:
                if r < n-1:
                    q.append((r+1, nc, k, total))
                else:
                    res.append(total)

print(min(res))