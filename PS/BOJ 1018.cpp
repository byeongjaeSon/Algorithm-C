#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];
int n, m, ret = 2500;

int paintColor(int y, int x, char color)
{
	int cnt = 0;
	for ( int i = y; i < y + 8; i++ )
	{
		for ( int j = x; j < x + 8; j++ )
		{
			if ( (i - y) % 2 == 0 )
			{
				if ( (j - x) % 2 == 0 )
				{
					if ( board[i][j] != color ) cnt++;
				}
				else
				{
					if ( board[i][j] == color ) cnt++;
				}
			}
			else
			{
				if ( (j - x) % 2 == 0 )
				{
					if ( board[i][j] == color ) cnt++;
				}
				else
				{
					if ( board[i][j] != color ) cnt++;
				}
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> board[i][j];

	for ( int i = 0; i <= n - 8; i++ )
	{
		for ( int j = 0; j <= m - 8; j++ )
		{
			int candi = min(paintColor(i, j, 'B'), paintColor(i, j, 'W'));
			ret = min(ret, candi);
		}
	}
	cout << ret << '\n';
	return 0;
}