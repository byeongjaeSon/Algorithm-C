#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> adjList;
int height[10001];
int treeSize[10001];
int parent[10001];

int dfs(int v, int h)
{
	height[v] = h;

	int tSize = 1;
	for ( int& next : adjList[v] )
		tSize += dfs(next, h + 1);

	return treeSize[v] = tSize;
}

int lca(int v, int u)
{
	if ( height[v] > height[u] )
		while ( height[v] != height[u] ) v = parent[v];
	else if ( height[v] < height[u] )
		while ( height[v] != height[u] ) u = parent[u];

	while ( v != u )
	{
		v = parent[v];
		u = parent[u];
	}

	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		memset(height, 0, sizeof(height));
		memset(treeSize, 0, sizeof(treeSize));
		memset(parent, 0, sizeof(parent));
		int V, E, v1, v2;
		cin >> V >> E >> v1 >> v2;
		adjList = vector<vector<int>>(V+1, vector<int>(0));

		int p, c;
		for ( int i = 0; i < E; i++ )
		{
			cin >> p >> c;
			adjList[p].push_back(c);
			parent[c] = p;
		}

		dfs(1, 0);

		int vertex = lca(v1, v2);

		cout << "#" << tc << " " << vertex << " " << treeSize[vertex] << '\n';

	}
	return 0;
}