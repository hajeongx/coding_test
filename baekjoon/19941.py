n, k = map(int, input().split())
arr = list(input())

cnt = 0
for i in range(n):
    if arr[i]=="P":
        l = max(0, i-k)
        r = min(n, i+k+1)
        for j in range(l, r):
            if arr[j]=="H":
                arr[j] = " "
                cnt += 1
                break
print(cnt)