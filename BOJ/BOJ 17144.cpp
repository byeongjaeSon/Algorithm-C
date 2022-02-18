#include <iostream>
#include <cstring>
using namespace std;

int room[51][51];
int cal[51][51];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int r, c, t, lowerY;


void diffusion()
{
	memset(cal, 0, sizeof(cal));
	for ( int i = 0; i < r; i++ )
		for ( int j = 0; j < c; j++ )
		{
			if ( room[i][j] <= 0 ) continue;

			int cnt = 0;
			int amount = room[i][j] / 5;
			for ( int direction = 0; direction < 4; direction++ )
			{
				int nextY = i + dy[direction];
				int nextX = j + dx[direction];
				if ( nextY < 0 || nextY >= r || nextX < 0 || nextX >= c ) continue;
				if ( (nextY == lowerY - 1 || nextY == lowerY) && nextX == 0 ) continue;

				cal[nextY][nextX] += amount;
				cnt++;
			}
			room[i][j] -= amount * cnt;
		}

	for ( int i = 0; i < r; i++ )
		for ( int j = 0; j < c; j++ )
			room[i][j] += cal[i][j];
}

void workAirCleaner()
{
	int upperY = lowerY - 1;

	// 위쪽 공기청정기
	for ( int y = upperY; y > 0; y-- )
		room[y][0] = room[y - 1][0];
	for ( int x = 0; x < c - 1; x++ )
		room[0][x] = room[0][x + 1];
	for ( int y = 0; y < upperY; y++ )
		room[y][c - 1] = room[y + 1][c - 1];
	for ( int x = c - 1; x > 0; x-- )
		room[upperY][x] = room[upperY][x - 1];

	// 아랫쪽 공기청정기
	for ( int y = lowerY; y < r - 1; y++ )
		room[y][0] = room[y + 1][0];
	for ( int x = 0; x < c - 1; x++ )
		room[r - 1][x] = room[r - 1][x + 1];
	for ( int y = r - 1; y > lowerY; y-- )
		room[y][c - 1] = room[y - 1][c - 1];
	for ( int x = c - 1; x > 0; x-- )
		room[lowerY][x] = room[lowerY][x - 1];

	room[upperY][1] = room[lowerY][1] = 0;
	room[upperY][0] = room[lowerY][0] = -1;
}


int main()
{
	int pos = 0;
	cin >> r >> c >> t;
	for ( int i = 0; i < r; i++ )
		for ( int j = 0; j < c; j++ )
		{
			cin >> room[i][j];
			if ( room[i][j] == -1 ) lowerY = i;
		}
	
	while ( t-- )
	{
		diffusion();
		workAirCleaner();
	}

	int sum = 2;
	for ( int i = 0; i < r; i++ )
		for ( int j = 0; j < c; j++ )
			sum += room[i][j];

	cout << sum << '\n';

	return 0;
}