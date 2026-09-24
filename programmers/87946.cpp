#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do {
        int power = k;
        int t = 0;
        for (const auto & dungeon : dungeons) {
            int a = dungeon[0];
            int b = dungeon[1];
            if (power >= a) {
                power -= b;
                t += 1;
            }
        }
        answer = max(answer, t);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}