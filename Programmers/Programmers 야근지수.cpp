#include <queue>

using namespace std;

// 시간 복잡도 분석
// N : 퇴근까지 남은 시간, M : works의 길이
// vector && max_element 사용 : O(N * M) 
// priority queue 사용 : O(max(NlgN , MlgM)) 
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for (int& work : works) {
        pq.push(work);
    }

    while (n--) {
        int work = pq.top();
        pq.pop();
        if (--work > 0) pq.push(work);
        if (pq.empty()) break;
    }

    while (!pq.empty()){
        int work = pq.top();
        pq.pop();
        answer += work * work;
    }
    
    return answer;
}
