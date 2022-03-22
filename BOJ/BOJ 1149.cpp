#include <iostream>
#include <cstring>

using namespace std;

int cache[1001][3];
int cost[1001][3];
int n;

int painting(int k, int color)
{
	if ( k == 0 ) return cost[k][color];

	int& ret = cache[k][color];
	if ( ret != -1 ) return ret;

	return ret = cost[k][color] + min(painting(k - 1, (color+1)%3), painting(k - 1, (color + 2) % 3));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	
	cin >> n;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < 3; j++ )
			cin >> cost[i][j];
	
	int answer = 987654321;
	for ( int color = 0; color < 3; color++ )
		answer = min(answer, painting(n-1, color));
	cout << answer << '\n';

	return 0;
}
