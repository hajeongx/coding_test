from copy import deepcopy

dr = [-1,-1,0,1,1,1,0,-1]
dc = [0,-1,-1,-1,0,1,1,1]

arr = []
info = {}
res = 0

for r in range(4):
    temp = list(map(int, input().split()))
    c = 0
    t = []
    for i in range(8):
        if i % 2 == 0:
            t.append(temp[i])
        else:
            info[t[c]] = [temp[i]-1, (r,c)]
            c += 1
    arr.append(t)


def dfs(arr, info, sr,sc,d,total):
    global res
    # 도둑말들 작은 것부터 돌면서 움직이기
    for i in sorted(info):
        k = info[i][0]
        if k >= 0:
            r, c = info[i][1]
            for j in range(8):
                nr, nc = r + dr[k], c + dc[k]
                if (nr,nc)!=(sr,sc) and 0<=nr<4 and 0<=nc<4:
                    # 해당 위치에 다른 도둑말 있는지 체크 후, 있다면 해당 말과 위치 뒤바꾸기
                    if arr[nr][nc] > 0:
                        info[arr[nr][nc]][1] = (r,c)
                    info[arr[r][c]] = [k, (nr,nc)]
                    arr[nr][nc], arr[r][c] = arr[r][c], arr[nr][nc]
                    break
                k = (k+1)%8
    # 술래말 움직이기 (먹을 수 있는 모든 경우의 수를 전부 dfs 재귀로 실행. 만약 없다면 return으로 반환)
    sr, sc = sr + dr[d], sc + dc[d]
    checked = False
    while 0<=sr<4 and 0<=sc<4:
        if arr[sr][sc] > 0:
            # sr,sc,d,total
            # 잡아먹기
            nd, num = info[arr[sr][sc]][0], arr[sr][sc]
            del info[arr[sr][sc]]
            arr[sr][sc] = 0
            # 재귀
            dfs(deepcopy(arr), deepcopy(info), sr,sc,nd,total+num)
            checked = True
            # 뱉어내기
            arr[sr][sc] = num
            info[arr[sr][sc]] = [nd, (sr,sc)]
        sr, sc = sr + dr[d], sc + dc[d]
    if not checked:
        res = max(res, total)
        return


d, num = info[arr[0][0]][0], arr[0][0]
del info[arr[0][0]]
arr[0][0] = 0

dfs(deepcopy(arr), deepcopy(info), 0,0,d,num)

print(res)