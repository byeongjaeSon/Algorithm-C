#include <iostream>
#include <cstring>
using namespace std;

int cost[1000][1000];
const int INF = 987654321;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		int n;
		cin >> n;

		for ( int i = 0; i < n; ++i )
			for ( int j = 0; j < n; ++j )
			{
				int cost_;
				cin >> cost_;
				
				if ( cost_ == 0 && i != j) cost[i][j] = INF;
				else cost[i][j] = cost_;
			}

		for ( int k = 0; k < n; ++k )
			for ( int i = 0; i < n; ++i )
			{
				int firstDist = cost[i][k];
				if ( firstDist == INF ) continue;
				for ( int j = 0; j < n; ++j )
					cost[i][j] = min(cost[i][j], firstDist + cost[k][j]);
			}

		int ret = INF;

		for ( int i = 0; i < n; ++i )
		{
			int sum = 0;
			for ( int j = 0; j < n; ++j )
				if (cost[i][j] != INF ) sum += cost[i][j];
			ret = min(ret, sum);
		}
			
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}