#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	const int INF = 987654321;
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> items(n, 0);
	for ( int i = 0; i < n; i++ )
		cin >> items[i];

	vector<vector<int>> cost(n, vector<int>(n, INF));
	for ( int i = 0; i < n; i++ )
		cost[i][i] = 0;

	for ( int i = 0; i < r; i++ )
	{
		int a, b, l;
		cin >> a >> b >> l;
		cost[a-1][b-1] = cost[b-1][a-1] = l;
	}

	for ( int k = 0; k < n; k++ )
		for ( int i = 0; i < n; i++ )
		{
			int firstDist = cost[i][k];
			if ( k == i || firstDist == INF ) continue;
			for ( int j = 0; j < n; j++ )
				cost[i][j] = min(cost[i][j], firstDist + cost[k][j]);
		}

	vector<int> results(n, 0);
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			if ( cost[i][j] <= m ) results[i] += items[j];
	

	cout << *max_element(results.begin(), results.end()) << '\n';
	return 0;
}