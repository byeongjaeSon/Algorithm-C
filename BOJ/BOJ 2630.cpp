#include <iostream>

using namespace std;

int paper[128][128];
int blueCnt = 0, whiteCnt = 0;

void solve(int y, int x, int size)
{
	bool needSlice = false;
	for ( int i = y; i < y + size; i++ )
	{
		for ( int j = x; j < x + size; j++ )
		{
			if ( paper[i][j] != paper[y][x] )
			{
				needSlice = true;
				break;
			}
		}
		if ( needSlice ) break;
	}

	if ( !needSlice )
	{
		if ( paper[y][x] == 0 ) whiteCnt++;
		else blueCnt++;
		return;
	}

	int half = size / 2;
	solve(y, x, half);
	solve(y + half, x, half);
	solve(y, x + half, half);
	solve(y + half, x + half, half);
}


int main()
{
	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> paper[i][j];
	
	solve(0, 0, n);
	cout << whiteCnt << '\n' << blueCnt << '\n';

	return 0;
}