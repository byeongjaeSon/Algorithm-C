#include <iostream>
#include <cstring>
using namespace std;

int n;
int cache[501][501];
int forest[501][501];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// 부분 문제 정의 : solve(y, x) = (y, x)에서 시작하여 탐색했을 때 이동할 수 있는 최대 경로 길이
int solve(int y, int x)
{
	int& ret = cache[y][x];
	if ( ret != -1 ) return ret;

	ret = 1;
	for ( int direction = 0; direction < 4; direction++ )
	{
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];

		if ( nextY < 0 || nextY >= n || x < 0 || x >= n ) continue;

		if ( forest[nextY][nextX] > forest[y][x] )
			ret = max(ret, 1 + solve(nextY, nextX));
	}

	return ret;
}


int main()
{
	cin >> n;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> forest[i][j];

	memset(cache, -1, sizeof(cache));

	
	int ans = 0;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			ans = max(ans, solve(i, j));

	cout << ans << '\n';

	return 0;
}