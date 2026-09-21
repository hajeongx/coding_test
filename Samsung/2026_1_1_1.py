from collections import deque

dr = [0,1,0,-1]
dc = [1,0,-1,0]

# 1. 거북 이동 (0번부터)
# 단 경로가 존재한다면 해당 경로의 첫 번째 칸으로 한 칸 이동 (n-1, n-1)
# 다른 거북이가 최단경로를 막고 있다면 멈추기.
def move(iter):
    global arr, turtle
    for i in range(m):
        # 0,1 에서 다른 거북이로 막힌 경우에는 멈춤. 나머지는 가는 방향으로 이동..
        if i in turtle:
            sr,sc = turtle[i]
            # 현재 맵 기준 각각 (n-1,n-1)까지의 최단 경로 탐색
            visited = [[0]*n for _ in range(n)]
            q = deque()
            for d in range(4):
                nr, nc = sr+dr[d], sc+dc[d]
                if 0<=nr<n and 0<=nc<n and arr[nr][nc]<1:
                    q.append((nr,nc,d))
                    visited[nr][nc] = 1
            z = -1
            while q:
                r, c, d = q.popleft()
                if r==n-1 and c==n-1:
                    z = d
                    break
                for k in range(4):
                    nr, nc = r+dr[k], c+dc[k]
                    if 0<=nr<n and 0<=nc<n and arr[nr][nc]<1 and not visited[nr][nc]:
                        q.append((nr,nc,d))
                        visited[nr][nc] = 1
            if z>=0:    # 찾은 최적 경로 방향으로 한칸 이동
                nr, nc = sr+dr[z], sc+dc[z]
                arr[sr][sc] = 0
                if nr==n-1 and nc==n-1:
                    ans[i] = iter
                    del turtle[i]
                else:
                    arr[nr][nc] = 3
                    turtle[i] = (nr,nc)

# 3. 화산 분출. 상하좌우로 열기를 뻗음. 이전 열기의 절반 내림으로. 산호초를 만나거나 0이되면 전파 멈춤. 여러 화산 열기 있으면 합산.
#  (현재 마그마 압력 + 해당 칸에 누적된 외부 열기) >= 분출 임계치(P) 분출 시작
# 거북이 자리의 열기가 20 이상이면 화석됨ㅠ. 그대로 장애물..
def eruption():
    global arr, vol, turtle, vv
    # 분출 임계치 이상인 화산이 존재할동안 폭발
    checked = True
    while checked:
        checked = False
        for r,c in vol:
            if vol[(r,c)][1]>0 and (vol[(r,c)][1]+vv[r][c] >= vol[(r,c)][0]):
                vv[r][c] += vol[(r,c)][0]
                for i in range(4):
                    fire = vol[(r,c)][0]//2
                    nr,nc = r,c
                    while fire > 0:
                        nr,nc = nr+dr[i], nc+dc[i]
                        if 0<=nr<n and 0<=nc<n:
                            if arr[nr][nc]==1:
                                break
                            vv[nr][nc] += fire
                        fire = fire//2
                vol[(r,c)][1] = 0
                checked = True
    for i in range(m):
        if i in turtle:
            r,c = turtle[i]
            if vv[r][c] >= 20:
                del turtle[i]
                arr[r][c] = 2

n, m, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)] # 1이면 산호초
turtle = {}
vol = {}
for i in range(m):  # 바닥 거북 화석은 2
    r,c = map(int, input().split())
    turtle[i] = (r,c)
    arr[r][c] = 3 # 살아있는 거북
for _ in range(k):  # 해저 화산 -1
    r, c, p = map(int, input().split())
    arr[r][c] = -1
    vol[(r,c)] = [p, 0]

ans = [-1]*m

for i in range(100):
    vv = [[0]*n for _ in range(n)] # 화산 열기 정보
    move(i+1)
    for r,c in vol:
        vol[(r,c)][1] += 10
    eruption()

for i in range(m):
    print(ans[i])