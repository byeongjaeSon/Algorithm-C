#include <iostream>
#include <cstring>
using namespace std;

int board[21][21];
bool isMerged[21][21];
int n, maxVal;

void moveLeft()
{
	memset(isMerged, false, sizeof(isMerged));

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 1; j < n; j++ )
		{
			if ( board[i][j] == 0 ) continue;

			int k = j - 1;
			for ( ; k >= 0; k-- )
				if ( board[i][k] != 0 ) break;

			int tmpVal = board[i][j];
			board[i][j] = 0;
			if ( k < 0 )
			{
				board[i][0] += tmpVal;
			}
			else if ( isMerged[i][k] || tmpVal != board[i][k] )
			{
				board[i][k+1] += tmpVal;
			}
			else
			{
				board[i][k] += tmpVal;
				isMerged[i][k] = true;
			}			
		}
	}
}

void moveRight()
{
	memset(isMerged, false, sizeof(isMerged));

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = n-2; j >= 0; j-- )
		{
			if ( board[i][j] == 0 ) continue;

			int k = j + 1;
			for ( ; k < n; k++ )
				if ( board[i][k] != 0 ) break;

			int tmpVal = board[i][j];
			board[i][j] = 0;
			if ( k >= n )
			{
				board[i][n-1] += tmpVal;
			}
			else if ( isMerged[i][k] || tmpVal != board[i][k] )
			{
				board[i][k - 1] += tmpVal;
			}
			else
			{
				board[i][k] += tmpVal;
				isMerged[i][k] = true;
			}
		}
	}
}

void moveUp()
{
	memset(isMerged, false, sizeof(isMerged));

	for ( int i = 1; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			if ( board[i][j] == 0 ) continue;

			int k = i - 1;
			for ( ; k >= 0; k-- )
				if ( board[k][j] != 0 ) break;

			int tmpVal = board[i][j];
			board[i][j] = 0;
			if ( k < 0 )
			{
				board[0][j] += tmpVal;
			}
			else if ( isMerged[k][j] || tmpVal != board[k][j] )
			{
				board[k + 1][j] += tmpVal;
			}
			else
			{
				board[k][j] += tmpVal;
				isMerged[k][j] = true;
			}
		}
	}
}

void moveDown()
{
	memset(isMerged, false, sizeof(isMerged));

	for ( int i = n - 2; i >= 0; i-- )
	{
		for ( int j = 0; j < n; j++ )
		{
			if ( board[i][j] == 0 ) continue;

			int k = i + 1;
			for ( ; k < n; k++ )
				if ( board[k][j] != 0 ) break;

			int tmpVal = board[i][j];
			board[i][j] = 0;
			if ( k >= n )
			{
				board[n-1][j] += tmpVal;
			}
			else if ( isMerged[k][j] || tmpVal != board[k][j] )
			{
				board[k - 1][j] += tmpVal;
			}
			else
			{
				board[k][j] += tmpVal;
				isMerged[k][j] = true;
			}
		}
	}
}


void solve(int moveCnt)
{
	if ( moveCnt == 5 )
	{
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				maxVal = max(maxVal, board[i][j]);

		return;
	}

	for ( int direction = 0; direction < 4; direction++ )
	{
		int tempBoard[21][21];
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				tempBoard[i][j] = board[i][j];


		if ( direction == 0 ) moveLeft();
		else if ( direction == 1 ) moveUp();
		else if ( direction == 2 ) moveRight();
		else if ( direction == 3 ) moveDown();

		solve(moveCnt + 1);

		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				board[i][j] = tempBoard[i][j];
	}
}

int main()
{
	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> board[i][j];
	
	solve(0);

	cout << maxVal << '\n';

	return 0;
}