#include <iostream>
#include <utility>
using namespace std;

int h, w;

int coverType[4][3][2] = { {{0,0},{1,0},{1,-1}},
						  {{0,0},{1,0},{1,1}},
						  {{0,0},{0,1},{1,1}},
						  {{0,0},{1,0},{0,1} } };

int coverBoard(char board[][20])
{	
	int cnt = 0;
	int y, x;
	for ( y = 0; y < h; y++ )
	{
		bool flag = false;
		for ( x = 0; x < w; x++ )
		{
			if ( board[y][x] == '.' )
			{
				flag = true;
				break;
			}
		}
		if ( flag == true ) break;
	}
	if ( y == h ) return 1;

	for ( int type = 0; type < 4; type++ )
	{
		bool canUseType = true;
		for ( int i = 1; i < 3; i++ )
		{
			pair<int, int> next = make_pair(y + coverType[type][i][0], x + coverType[type][i][1]);
			if ( next.first >= h || next.second >= w || board[next.first][next.second] == '#' )
			{
				canUseType = false;
				break;
			}
		}

		if ( canUseType )
		{
			board[y][x] = board[y + coverType[type][1][0]][x + coverType[type][1][1]]
				= board[y + coverType[type][2][0]][x + coverType[type][2][1]] = '#';
			cnt += coverBoard(board);
			board[y][x] = board[y + coverType[type][1][0]][x + coverType[type][1][1]]
				= board[y + coverType[type][2][0]][x + coverType[type][2][1]] = '.';
		}
	}
	return cnt;
}


int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{
		char board[20][20];
		int blankCnt = 0;
		cin >> h >> w;
		for ( int y = 0; y < h; y++ )
		{
			for ( int x = 0; x < w; x++ )
			{
				cin >> board[y][x];
				if ( board[y][x] == '.' ) blankCnt++;
			}
		}
		if ( blankCnt % 3 != 0 ) cout << 0 << '\n';
		else cout << coverBoard(board) << '\n';
	}
	return 0;
}