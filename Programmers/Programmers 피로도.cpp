#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int currFatigue = k, visitCnt = 0;
        for (vector<int>& dungeon : dungeons) {
            int minNeedFatigue = dungeon[0], useFatigue = dungeon[1];
            if (currFatigue >= minNeedFatigue) {
                currFatigue -= useFatigue;
                visitCnt++;
                continue;
            }
            break;
        }
        answer = max(answer, visitCnt);
	} while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}
