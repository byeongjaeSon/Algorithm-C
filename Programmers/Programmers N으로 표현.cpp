#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> dp(9);

int solution(int N, int number) {
    int answer = -1;
    for (int useCnt = 1; useCnt <= 8; useCnt++) {
        for (int a = useCnt; a >= 0; a--) {
            int b = useCnt - a;
            if (a == useCnt) {
                int result = 0;
                for (int i = 0; i < useCnt; i++) result = result * 10 + N;
                if (result == number) {
                    answer = useCnt;
                    break;
                }
                dp[useCnt].insert(result);
            }
            else {
                for (auto iter1 = dp[a].begin(); iter1 != dp[a].end(); iter1++) {
                    for (auto iter2 = dp[b].begin(); iter2 != dp[b].end(); iter2++) {
                        int result = (*iter1) * (*iter2);
                        if (result == number) {
                            answer = useCnt;
                            break;
                        }
                        dp[useCnt].insert(result);
                        
                        if (*iter2 != 0) {
                            result = (*iter1) / (*iter2);
                            if (result == number) {
                                answer = useCnt;
                                break;
                            }
                            dp[useCnt].insert(result);
                        }
                        
                        result = (*iter1) + (*iter2);
                        if (result == number) {
                            answer = useCnt;
                            break;
                        }
                        dp[useCnt].insert(result);
                        
                        result = (*iter1) - (*iter2);
                        if (result == number) {
                            answer = useCnt;
                            break;
                        }
                        dp[useCnt].insert(result);
                    }
                    if (answer != -1) break;
                }
                if (answer != -1) break;
            }
            if (answer != -1) break;
        }
        if (answer != -1) break;
    }
    
    return answer;
}
