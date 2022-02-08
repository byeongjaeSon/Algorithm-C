#include <iostream>
using namespace std;

int board[20][20];

bool canSliceVertical(int y_lo, int y_hi, int x)
{
	for ( int y = y_lo; y <= y_hi; y++ )
		if ( board[y][x] == 2 ) return false;
	return true;
}

bool canSliceHorizontal(int x_lo, int x_hi, int y)
{
	for ( int x = x_lo; x <= x_hi; x++ )
		if ( board[y][x] == 2 ) return false;
	return true;
}

int solve(int y_lo, int y_hi, int x_lo, int x_hi, char pre)
{
	int numOfGem = 0, numOfWaste = 0;
	for ( int y = y_lo; y <= y_hi; y++ )
	{
		for ( int x = x_lo; x <= x_hi; x++ )
		{
			if ( board[y][x] == 2 ) numOfGem++;
			else if ( board[y][x] == 1 ) numOfWaste++;
		}
	}
	if ( numOfGem == 0 ) return 0;
	else if ( numOfGem == 1 && numOfWaste == 0 ) return 1;

	int ret = 0;
	for ( int y = y_lo; y <= y_hi; y++ )
	{
		for ( int x = x_lo; x <= x_hi; x++ )
		{
			if ( board[y][x] == 1 )
			{
				if ( pre != 'h' && canSliceHorizontal(x_lo, x_hi, y) )
					ret += solve(y_lo, y - 1, x_lo, x_hi, 'h') * solve(y + 1, y_hi, x_lo, x_hi, 'h');
				if ( pre != 'v' && canSliceVertical(y_lo, y_hi, x) )
					ret += solve(y_lo, y_hi, x_lo, x - 1, 'v') * solve(y_lo, y_hi, x + 1, x_hi, 'v');
			}
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	for ( int y = 0; y < n; y++ )
		for ( int x = 0; x < n; x++ )
			cin >> board[y][x];
	int answer = solve(0, n - 1, 0, n - 1, ' ');
	if ( answer == 0 ) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}