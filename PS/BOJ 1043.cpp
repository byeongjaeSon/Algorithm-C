#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


bool visited[51];

bool dfs(vector<bool>& knowTruth, vector<vector<bool>>& adj, int start)
{
	if ( knowTruth[start] ) return true; 
	visited[start] = true;

	for ( int idx = 1; idx < adj[start].size(); idx++ )
	{
		if ( adj[start][idx] == false || visited[idx] ) continue;
		if ( dfs(knowTruth, adj, idx) ) return true;
	}
	return false;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<bool> knowTruth(n + 1, false);
	for ( int i = 0; i < k; i++ )
	{
		int pIdx;
		cin >> pIdx;
		knowTruth[pIdx] = true;
	}

	vector<vector<int>> inputs(m);
	for ( int i = 0; i < m; i++ )
	{
		int num;
		cin >> num;
		for ( int j = 0; j < num; j++ )
		{
			int id;
			cin >> id;
			inputs[i].push_back(id);
		}
	}

	vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < inputs[i].size(); j++ )
			for ( int k = j + 1; k < inputs[i].size(); k++ )
				adj[inputs[i][j]][inputs[i][k]] = adj[inputs[i][k]][inputs[i][j]] = true;

	int cnt = 0;
	for ( int i = 0; i < m; i++ )
	{
		bool flag = false;
		for ( int j : inputs[i] )
		{
			memset(visited, false, sizeof(visited));
			if ( dfs(knowTruth, adj, j) == true )
			{
				flag = true;
				break;
			}
		}
		if ( flag == false ) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}