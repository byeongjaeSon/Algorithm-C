#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    long long q1Sum = 0, q2Sum = 0;
    for (int& element : queue1) {
        q1.push(element);
        q1Sum += element;
    }
    for (int& element : queue2) {
        q2.push(element);
        q2Sum += element;
    }
    
    if ((q1Sum + q2Sum) % 2 == 1) {
        return -1;
    }
    
    long long targetSum = (q1Sum + q2Sum) / 2;
    
    while (!q1.empty() && !q2.empty()) {
        if (q1Sum > targetSum) {
            q1Sum -= q1.front();
            q1.pop();
            answer++;
        }
        else if (q1Sum < targetSum) {
            int q2Front = q2.front();
            q1.push(q2Front); q2.pop();
            q1Sum += q2Front;
            answer++;
        }
        else return answer;
    }
    
    return -1;
}
