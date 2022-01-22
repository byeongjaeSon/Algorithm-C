#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 987654321

long long dist[501];
vector<pair<pair<int, int>,int>> edgeList;

bool bellmanFord(int n)
{
	for ( int i = 0; i < n - 1; i++ )
	{
		// relaxation
		for ( auto edge : edgeList )
		{
			int u = edge.first.first;
			int v = edge.first.second;
			int cost = edge.second;

			if ( dist[u] == INF ) continue; // 한 번이라도 계산된 정점이어야한다. 

			if ( dist[v] > dist[u] + cost )
				dist[v] = dist[u] + cost;
		}
	}

	for ( auto edge : edgeList )
	{
		int u = edge.first.first;
		int v = edge.first.second;
		int cost = edge.second;

		if ( dist[u] == INF ) continue;

		if ( dist[v] > dist[u] + cost )
			return false;
	}

	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;

	fill(&dist[0], &dist[501], INF);
	dist[1] = 0;

	for ( int i = 0; i < m; i++ )
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edgeList.push_back(make_pair(make_pair(from, to), cost));
	}

	if ( bellmanFord(n) == false ) cout << -1 << '\n';
	else
	{
		for ( int i = 2; i <= n; i++ )
		{
			if ( dist[i] == INF ) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	
	return 0;
}