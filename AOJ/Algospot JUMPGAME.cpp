#include <iostream>
#include <cstdlib>
using namespace std;

int board[100][100];
bool visited[100][100];
int c, n;
bool canReachEnd(int y, int x)
{
	// 기저 사례
	if ( y == n - 1 && x == n - 1 ) return true;
	if ( y >= n || x >= n ) return false;

	// 이미 방문한 곳인지 체크
	if ( visited[y][x] ) return false;
	visited[y][x] = true;
	int jumpRange = board[y][x];
	return (canReachEnd(y + jumpRange, x) || canReachEnd(y, x + jumpRange));
}

int main()
{
	cin >> c;
	while ( c-- )
	{
		cin >> n;
		memset(visited, false, sizeof(visited));
		for ( int y = 0; y < n; y++ )
			for ( int x = 0; x < n; x++ )
				cin >> board[y][x];
		if ( canReachEnd(0,0) ) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}