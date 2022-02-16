#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define INF 2000000000
using namespace std;

vector<vector<pair<int,int>>> adjList(10001);
int dist[10001];

int main()
{
	int n, m, s, e;
	cin >> n >> m;

	for ( int i = 0; i < m; i++ )
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adjList[u].push_back(make_pair(cost, v));
	}
	cin >> s >> e;

	for ( int i = 0; i <= n; i++ )
		dist[i] = INF;

	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push(make_pair(0, s));
	
	while ( !pq.empty() )
	{
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if ( dist[vertex] < cost ) continue;

		for ( pair<int, int>& next : adjList[vertex] )
		{
			if ( dist[next.second] > dist[vertex] + next.first )
			{
				dist[next.second] = dist[vertex] + next.first;
				pq.push(make_pair(dist[next.second], next.second));
			}
		}
	}

	cout << dist[e] << '\n';
	return 0;
}