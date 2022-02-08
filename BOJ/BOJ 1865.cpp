#include <iostream>
#include <algorithm>

using namespace std;

int cost[501][501];
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while ( tc-- )
	{
		int n, m, w, s, e, t;
		cin >> n >> m >> w;

		fill(&cost[0][0], &cost[500][501], INF);

		for ( int i = 0; i < n; i++ )
			cost[i + 1][i + 1] = 0;

		for ( int i = 0; i < m; i++ )
		{
			cin >> s >> e >> t;
			if ( t < cost[s][e] )
				cost[s][e] = cost[e][s] = t;
		}

		for ( int i = 0; i < w; i++ )
		{
			cin >> s >> e >> t;
			cost[s][e] = -t;
		}

		for ( int k = 1; k <= n; k++ ) // 경유점
			for ( int i = 1; i <= n; i++ ) // 시작점
			{
				int firstDist = cost[i][k];
				if ( firstDist == INF ) continue;
				for ( int j = 1; j <= n; j++ ) // 도착점
					cost[i][j] = min(cost[i][j], firstDist + cost[k][j]);
			}

		bool flag = false;
		for ( int i = 0; i < n; i++ )
		{
			if ( cost[i + 1][i + 1] < 0 )
			{
				flag = true;
				break;
			}
		}

		if ( flag == true ) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}