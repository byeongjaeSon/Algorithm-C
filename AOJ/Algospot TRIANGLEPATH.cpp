#include <iostream>
#include <cstring>
using namespace std;

int triangle[101][101];
int cache[101][101];
int n;

// 부분 최적 구조!
int findMaxPath(int y, int x)
{
	if ( y == n - 1 ) return triangle[y][x];

	int& ret = cache[y][x];
	if ( ret != -1 ) return ret;
	return ret = max(findMaxPath(y + 1, x), findMaxPath(y + 1, x + 1)) + triangle[y][x];
}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < i + 1; j++ )
				cin >> triangle[i][j];
		cout << findMaxPath(0, 0) << '\n';
	}
	return 0;
}