#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int parent[100];

typedef struct Info_ {
    int from;
    int to;
    int dist;
} Info;

struct cmp {
    bool operator()(const Info& a, const Info& b){
        return a.dist > b.dist;
    }
};

int findSet(int v) {    
	if (parent[v] != v) return parent[v] = findSet(parent[v]);
	else return v;
}

int solution(int n, vector<vector<int>> costs) {
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    priority_queue<Info, vector<Info>, cmp> pq;
    for (vector<int>& cost : costs) {
        Info info;
        info.from = cost[0], info.to = cost[1], info.dist = cost[2];
        pq.push(info);
    }
    
    int selectCnt = 0, sumDist = 0;
    while (!pq.empty()) {
        int root1 = findSet(pq.top().from);
        int root2 = findSet(pq.top().to);
        int dist = pq.top().dist;
        pq.pop();
        
        if (root1 == root2) continue;

        parent[root1] = root2;
        sumDist += dist;
        if (++selectCnt == n-1) break;
    }
    
    return sumDist;
}
