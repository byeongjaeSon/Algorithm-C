#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define INF 987654321

int dist[20001];

void dijkstra(int start, int n, vector<vector<pair<int, int>>>& adjList)
{
	fill(dist, dist + n + 1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while ( !pq.empty() )
	{
		int weight = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		if ( weight > dist[vertex] ) continue;

		for ( pair<int,int>& node : adjList[vertex] )
		{
			if ( dist[node.first] > dist[vertex] + node.second )
			{
				dist[node.first] = dist[vertex] + node.second;
				pq.push(make_pair(dist[node.first], node.first));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;

	vector<vector<pair<int, int>>> adjList(v+1);

	for ( int i = 0; i < e; i++ )
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		adjList[from].push_back(make_pair(to, weight));
	}

	dijkstra(k, v, adjList);

	for ( int i = 1; i <= v; i++ )
	{
		if ( dist[i] == INF ) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
}