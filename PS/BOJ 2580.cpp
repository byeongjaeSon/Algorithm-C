#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int board[9][9];
stack<pair<int, int>> blankPos;

bool isRowConflict(int y, int num)
{
	for ( int x = 0; x < 9; x++ )
		if ( board[y][x] == num ) return true;

	return false;
}

bool isColConflict(int x, int num)
{
	for ( int y = 0; y < 9; y++ )
		if ( board[y][x] == num ) return true;

	return false;
}

bool isSquareConflict(int y, int x, int num)
{
	int startY = (y / 3) * 3;
	int startX = (x / 3) * 3;

	for ( int dy = 0; dy < 3; dy++ )
		for ( int dx = 0; dx < 3; dx++ )
			if ( board[startY + dy][startX + dx] == num ) return true;
	return false;
}

void printBoard()
{
	for ( int i = 0; i < 9; i++ )
	{
		for ( int j = 0; j < 9; j++ )
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

bool sudoku()
{
	if ( blankPos.empty() ) return true;

	int y = blankPos.top().first;
	int x = blankPos.top().second;

	for ( int num = 1; num <= 9; num++ )
	{
		if ( !isRowConflict(y, num) && !isColConflict(x, num) && !isSquareConflict(y, x, num) )
		{
			board[y][x] = num;
			blankPos.pop();
			if ( sudoku() ) return true;
			board[y][x] = 0;
			blankPos.push(make_pair(y, x));
		}
	}
	return false;
}

int main()
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
		{
			cin >> board[i][j];
			if ( board[i][j] == 0 ) blankPos.push(make_pair(i, j));
		}

	if ( sudoku() )
		printBoard();

	return 0;
}