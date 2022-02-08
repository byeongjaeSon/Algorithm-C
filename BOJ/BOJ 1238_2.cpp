#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int cost[1001][1001];
const int INF = 987654321;

vector<int> times;

struct cmp
{
	bool operator() (pair<int, int> v1, pair<int, int> v2)
	{
		if ( v1.second > v2.second ) return true;
		else return false;
	}
};

void dijkstra(int start, int dest, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> dist(n + 1, INF);

	dist[start] = 0;
	pq.push(make_pair(start, 0));

	while ( !pq.empty() )
	{
		// 아직 방문하지 않았고, 시작점으로부터 거리가 최소인 노드 선택.
		int u = pq.top().first;
		if ( u == dest && start != dest )
		{
			times[start] += pq.top().second;
			return;
		}

		pq.pop();

		// relaxation
		for ( int v = 1; v <= n; v++ )
		{
			if ( dist[v] > dist[u] + cost[u][v] )
			{
				dist[v] = dist[u] + cost[u][v];
				pq.push(make_pair(v, dist[v]));
			}
		}
	}

	for ( int v = 1; v <= n; v++ )
		times[v] += dist[v];
}


int main()
{
	int n, x, m;
	cin >> n >> m >> x;

	fill(&cost[0][0], &cost[1000][1001], INF);
	for ( int i = 0; i < m; i++ )
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		cost[from][to] = weight;
	}

	for ( int i = 0; i < n; i++ )
		cost[i + 1][i + 1] = 0;

	times = vector<int>(n + 1, 0);

	for ( int start = 1; start <= n; start++ )
		dijkstra(start, x, n);

	cout << *max_element(times.begin(), times.end()) << '\n';

	return 0;
}