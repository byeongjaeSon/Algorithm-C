#include <iostream>
using namespace std;

int cost[101][101];
const int INF = 987654321;

int main()
{
	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			cost[i][j] = INF;


	for ( int i = 0; i < m; i++ )
	{
		int u, v, c;
		cin >> u >> v >> c;
		cost[u][v] = min(cost[u][v], c);
	}

	for ( int i = 1; i <= n; i++ )
		cost[i][i] = 0;

	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			if ( k == i || cost[i][k] == INF ) continue;
			for ( int j = 1; j <= n; j++ )
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			if ( cost[i][j] == INF ) cout << 0 << ' ';
			else cout << cost[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}