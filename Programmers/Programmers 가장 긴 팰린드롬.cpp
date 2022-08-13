#include <algorithm>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0, len = s.length();
    for (int i = 0; i < len; i++) {
        // Case1 : 중간 문자열 기준 좌우 대칭 ex) a b c b a
        int tempAns = 1;
        for (int dx = 1; (i - dx >= 0 && i + dx < len); dx++) {
            if (s[i-dx] == s[i+dx]) tempAns += 2;
            else break;
        }
        answer = max(answer, tempAns);
       
        // Case2 : 중간 문자열 포함 안하고 좌우 대칭 ex) a b b a
        tempAns = 0;
         for (int dx = 1; (i-dx+1 >= 0 && i+dx < len); dx++) {
            if (s[i-dx+1] == s[i+dx]) tempAns += 2;
            else break;
        }   
        answer = max(answer, tempAns);
    }
    return answer;
}
