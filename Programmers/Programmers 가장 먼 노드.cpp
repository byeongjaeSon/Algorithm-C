#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> dist;



int solution(int n, vector<vector<int>> edge)
{

    int size = edge.size();
    adjList = vector<vector<int>>(n + 1, vector<int>(0));
    visited = vector<bool>(n + 1, false);
    dist = vector<int>(n + 1, 0);

    for ( int i = 0; i < size; i++ )
    {
        int u = edge[i][0];
        int v = edge[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<int> q;
    int distance = 0;
    q.push(1);
    visited[1] = true;
    dist[1] = 0;
    while ( !q.empty() )
    {
        int qSize = q.size();
        for ( int i = 0; i < qSize; i++ )
        {
            int curr = q.front();
            q.pop();

            dist[curr] = distance;

            for ( int& next : adjList[curr] )
            {
                if ( !visited[next] )
                {
                    visited[next] = true;
                    q.push(next);
                }
            }

        }
        distance++;
    }

    int maxDist = *max_element(dist.begin(), dist.end());
    int answer = 0;
    for ( int& d : dist )
        if ( d == maxDist ) answer++;

    return answer;
}