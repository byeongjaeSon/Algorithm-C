#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1001][1001];
const int INF = 987654321;

int main()
{
	int n, x, m;
	cin >> n >> m >> x;

	fill(&cost[0][0], &cost[1000][1001], INF);
	for ( int i = 0; i < m; i++ )
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		cost[from][to] = weight;
	}

	for ( int i = 0; i < n; i++ )
		cost[i + 1][i + 1] = 0;

	for ( int k = 1; k <= n; k++ )
		for ( int i = 1; i <= n; i++ )
		{
			if ( k == i || cost[i][k] == INF ) continue;
			for ( int j = 1; j <= n; j++ )
			{
				if ( k == j || i == j || cost[k][j] == INF ) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
			

	vector<int> times(n);
	for ( int i = 0; i < n; i++ )
		times[i] = cost[i + 1][x] + cost[x][i + 1];

	cout << *max_element(times.begin(), times.end()) << '\n';

	return 0;
}