#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 10000000;
vector<vector<pair<int, int>>> adjList(801);
int dist[801];

int main()
{
	int n, e, v1, v2;
	cin >> n >> e;
	for ( int i = 0; i < e; i++ )
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adjList[u].push_back(make_pair(cost, v));
		adjList[v].push_back(make_pair(cost, u));
	}
	cin >> v1 >> v2;

	for ( int i = 0; i <= n; i++ )
		dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	while ( !pq.empty() )
	{
		int vertex = pq.top().second;
		int cost = pq.top().first;
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

	int distV1 = dist[v1], distV2 = dist[v2];

	for ( int i = 0; i <= n; i++ )
		dist[i] = INF;

	dist[v1] = 0;
	pq.push(make_pair(0, v1));
	while ( !pq.empty() )
	{
		int vertex = pq.top().second;
		int cost = pq.top().first;
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

	int distV1toV2 = dist[v2];
	int distV1toN = dist[n];


	for ( int i = 0; i <= n; i++ )
		dist[i] = INF;

	dist[v2] = 0;
	pq.push(make_pair(0, v2));
	while ( !pq.empty() )
	{
		int vertex = pq.top().second;
		int cost = pq.top().first;
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

	int distV2toN = dist[n];

	// 1. s -> v1 -> v2 -> e
	int path1 = distV1toV2 + distV1 + distV2toN;
	// 2. s -> v2 -> v1 -> e
	int path2 = distV1toV2 + distV2 + distV1toN;

	int result = -1;
	if ( path1 < INF || path2 < INF )
		result = min(path1, path2);

	cout << result << '\n';
	return 0;
}