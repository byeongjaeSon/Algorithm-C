#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> result;
int n, m;

void dfs(int here)
{
	visited[here] = true;
	for ( int& next : adjList[here] )
	{
		if ( !visited[next] )
			dfs(next);
	}
	result.push_back(here);
}

void dfsAll()
{
	for ( int curr = 1; curr <= n; curr++ )
	{
		if ( !visited[curr] )
			dfs(curr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	adjList.resize(n + 1);
	visited.resize(n + 1, false);
	for ( int i = 0; i < m; i++ )
	{
		int u, v;
		cin >> u >> v;
		adjList[v].push_back(u);
	}

	dfsAll();

	for ( int& node : result )
		cout << node << ' ';

	return 0;
}