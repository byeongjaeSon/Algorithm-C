#include <iostream>
#include <cstring>
using namespace std;

int board[100][100];
int cache[100][100];
int n;

int canJump(int y, int x)
{
	if ( y >= n || x >= n ) return false;
	if ( y == n - 1 && x == n - 1 ) return true;

	int& ret = cache[y][x];
	if ( ret != -1) return ret;

	int stride = board[y][x];
	return ret = (canJump(y + stride, x) || canJump(y, x + stride));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	while ( c-- )
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
	
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				cin >> board[i][j];

		if ( canJump(0, 0) ) cout << "YES" << '\n';
		else cout << "NO" << '\n';	
	}
	return 0;
}