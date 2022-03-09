#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1001];
int t, n, k;

vector<vector<int>> adjList;
vector<int> order;
vector<bool> visited;

void dfs(int here)
{
	visited[here] = true;

	for ( int& next : adjList[here] )
		if ( !visited[next] ) dfs(next);

	order.push_back(here);
}

void topologySort()
{
	visited = vector<bool>(n + 1, false);
	order.clear();

	for ( int i = 1; i <= n; i++ )
		if ( !visited[i] ) dfs(i);

	reverse(order.begin(), order.end());
}

int solve(int w)
{
	vector<int> dist(n + 1, 0);
	for ( int i = 1; i <= n; i++ )
		dist[i] = cost[i];

	for ( int e : order )
	{
		for ( int v : adjList[e] )
		{
			if ( dist[v] <= dist[e] + cost[v] )
				dist[v] = dist[e] + cost[v];
		}
	}
	return dist[w];
}

int main()
{
	cin >> t;
	while ( t-- )
	{
		adjList.clear();
		order.clear();
		visited.clear();

		cin >> n >> k;

		for ( int i = 1; i <= n; i++ )
			cin >> cost[i];

		adjList.resize(n + 1);

		for ( int i = 0; i < k; i++ )
		{
			int x, y;
			cin >> x >> y;
			adjList[x].push_back(y);
		}

		topologySort();

		int w;
		cin >> w;
		cout << solve(w) << '\n';
	}

	return 0;
}