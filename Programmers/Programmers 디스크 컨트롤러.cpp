#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmpRequestPoint(vector<int>& a, vector<int>& b) {
    return a[0] > b[0];
}

struct cmpProcessTime{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, jobCnt = jobs.size(), currTime = 0;
   
    sort(jobs.begin(), jobs.end(), cmpRequestPoint);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmpProcessTime> pq;
    
    while ((!jobs.empty()) || (!pq.empty())) {
        if (pq.empty()){
            currTime = jobs.back()[0] + jobs.back()[1];
            answer += currTime - jobs.back()[0];
            jobs.pop_back();
        } else {
            pair<int,int> shortestJob = pq.top();
            pq.pop();
            currTime += shortestJob.second;
            answer += currTime - shortestJob.first;
        }
        
        for (int idx = jobs.size()-1; idx >= 0; idx--) {
            if (jobs[idx][0] > currTime) break;
            pq.push({jobs[idx][0], jobs[idx][1]});
            jobs.pop_back();
        } 
    }
    answer = answer / jobCnt;
    return answer;
}
