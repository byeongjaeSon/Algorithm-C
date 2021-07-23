#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int S[10][100000];
int cache[10][100000];

int main()
{
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	for ( int y = 0; y < m; y++ )
		for ( int x = 0; x < n; x++ )
			cin >> S[y][x];

	for ( int i = 0; i < m; i++ )
		cache[i][0] = S[i][0];

	for ( int day = 1; day < n; day++ )
	{
		for ( int i = 0; i < m; i++ )
		{
			cache[i][day] = cache[i][day - 1] + S[i][day] / 2;
			for ( int j = 0; j < m; j++ )
			{
				if ( i == j ) continue;
				cache[i][day] = max(cache[i][day], cache[j][day - 1] + S[i][day]);
			}
		}
	}

	int result = 0;
	for ( int idx = 0; idx < m; idx++ )
		result = max(result, cache[idx][n - 1]);
	cout << result << '\n';
	return 0;
}