#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> dp(9);

int solution(int N, int number) {
    int result = 0;
    for (int useCnt = 1; useCnt <= 8; useCnt++) {
        for (int a = useCnt; a >= 0; a--) {
            if (a == useCnt) {
                result = 0;
                for (int i = 0; i < useCnt; i++) result = result * 10 + N;
                if (result == number) return useCnt;
                dp[useCnt].insert(result);
                continue;
            }
            int b = useCnt - a;
            for (auto iter1 = dp[a].begin(); iter1 != dp[a].end(); iter1++) {
                for (auto iter2 = dp[b].begin(); iter2 != dp[b].end(); iter2++) {
                    result = (*iter1) + (*iter2);
                    if (result == number) return useCnt;
                    dp[useCnt].insert(result);

                    result = (*iter1) - (*iter2);
                    if (result == number) return useCnt;
                    dp[useCnt].insert(result);
                    
                    result = (*iter1) * (*iter2);
                    if (result == number) return useCnt;
                    dp[useCnt].insert(result);

                    if (*iter2 == 0) continue;
                    result = (*iter1) / (*iter2);
                    if (result == number) return useCnt;
                    dp[useCnt].insert(result);                
                }
            }
        }
    }
    return -1;
}}
