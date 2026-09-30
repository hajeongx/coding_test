#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int nr, nc, x, y;
    vector<vector<int>> arr(m,vector<int>(n,0));
    vector<int> dr={0,1}, dc={1,0};
    for(const auto& puddle:puddles){
        x = puddle[0]-1; y = puddle[1]-1;
        arr[x][y] = -1;
    }
    arr[0][0] = 1;
    for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            if(arr[r][c]!=-1){
                for(int d=0;d<2;d++){
                    nr = r+dr[d];
                    nc = c+dc[d];
                    if(nr<m && nc<n && arr[nr][nc]!=-1){
                        arr[nr][nc] = (arr[nr][nc]+arr[r][c])%1000000007;
                    }
                }
            }
        }
    }
    return arr[m-1][n-1];
}