#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> arr(n, vector<int>(n,0));
    int r = -1, c = 0, num = 1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i%3==0){
                r += 1;
            }
            else if(i%3==1){
                c += 1;
            }
            else{
                r -= 1;
                c -= 1;
            }
            arr[r][c] = num;
            num += 1;
        }
    }
    
    vector<int> answer;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}