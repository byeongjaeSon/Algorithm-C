#include <vector>
#include <queue>
#include <utility>

#define INF 987654321
using namespace std;

vector<vector<int>> cost;
vector<int> dist;

void dijikstra(int N)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push(make_pair(0, 1)); // cost , town
    
    while(!pq.empty())
    {
        pair<int,int> curr = pq.top();
        pq.pop();
        
        int nowCost = curr.first;
        int nowTown = curr.second;
        
        if (dist[nowTown] < nowCost) continue;
        
        for (int next = 1; next <= N; next++) {
            
            if (cost[nowTown][next] == INF) continue;
            
            if (dist[next] > dist[nowTown] + cost[nowTown][next])
            {
                dist[next] = dist[nowTown] + cost[nowTown][next];
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int getNumOfOrderTown(int N, int K)
{
    int cnt = 0;
    for (int town = 1; town <= N; town++)
        if (dist[town] <= K) cnt++;
    return cnt;
}

int solve(int N, int K)
{
    dijikstra(N);
    return getNumOfOrderTown(N, K);
}

int solution(int N, vector<vector<int>> road, int K) {
    
    dist.resize(N+1, INF);
    cost.resize(N+1, vector<int>(N+1, INF));
    
    int roadCnt = road.size();
    for (int i = 0; i < roadCnt; i++) {
        int u = road[i][0];
        int v = road[i][1];
        int weight = road[i][2];
        
        cost[u][v] = min(cost[u][v], weight);
        cost[v][u] = min(cost[v][u], weight);
    }
    for (int town = 1; town <= N; town++ )
        cost[town][town] = 0;
    
    int answer = solve(N, K);
    return answer;
}