#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, cnt;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int curr)
{
	int node = 1, edge = 0;
	visited[curr] = true;
	for ( int next : adj[curr] )
	{
		cnt++;
		if ( !visited[next] ) node += dfs(next);
	}
	return node;
}

int dfsAll()
{
	int numTree = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( !visited[i] )
		{
			int node = dfs(i);
			if ( node - 1 == cnt / 2 ) numTree++;
			cnt = 0;
		}
	}
	return numTree;
}

int main()
{
	int caseNum = 1;
	while ( true )
	{
		cin >> n >> m;
		if ( n == 0 && m == 0 ) break;
		visited = vector<bool>(n + 1, false);
		adj = vector<vector<int>>(n + 1);
		for ( int i = 0; i < m; i++ )
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int num = dfsAll();
		if ( num == 0 ) cout << "Case " << caseNum << ": No trees.\n";
		else if ( num == 1 ) cout << "Case " << caseNum << ": There is one tree.\n";
		else cout << "Case " << caseNum << ": A forest of " << num << " trees.\n";
		caseNum++;
	}
	return 0;
}