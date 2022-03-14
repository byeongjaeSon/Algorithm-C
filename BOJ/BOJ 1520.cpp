#include <iostream>
#include <cstring>
using namespace std;

#define MAX 501

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,1,0,-1 };
int map[MAX][MAX];
int cache[MAX][MAX];
int m, n;

int findNumOfdownhillPath(int y, int x)
{
	if ( y == 0 && x == 0 ) return 1;
	
	int& ret = cache[y][x];
	if ( ret != -1 ) return ret;

	ret = 0;
	for ( int direction = 0; direction < 4; direction++ )
	{
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];

		if ( nextY < 0 || nextY >= m || nextX < 0 || nextX >= n ) continue;
		if ( map[nextY][nextX] <= map[y][x] ) continue;
		
		ret += findNumOfdownhillPath(nextY, nextX);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> map[i][j];
	
	memset(cache, -1, sizeof(cache));

	cout << findNumOfdownhillPath(m - 1, n - 1) << '\n';

	return 0;
}