#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int n, m, ret;
int lab[8][8];
queue<pair<int, int>> virusPos;

void bfs()
{
	queue<pair<int, int>> q = virusPos;
	int temp[8][8];
	for ( int y = 0; y < n; y++ )
		for ( int x = 0; x < m; x++ )
			temp[y][x] = lab[y][x];

	while ( !q.empty() )
	{
		int qSize = q.size();
		for ( int i = 0; i < qSize; i++ )
		{
			pair<int, int> currPos = q.front();
			q.pop();
			for ( int direction = 0; direction < 4; direction++ )
			{
				int nextY = currPos.first + dy[direction];
				int nextX = currPos.second + dx[direction];

				if ( nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > m - 1 ) continue;
				if ( temp[nextY][nextX] == 1 || temp[nextY][nextX] == 2 ) continue;
				temp[nextY][nextX] = 2;
				q.push(make_pair(nextY, nextX));
			}
		}
	}

	int num = 0;
	for ( int y = 0; y < n; y++ )
		for ( int x = 0; x < m; x++ )
			if ( temp[y][x] == 0 ) num++;

	if ( num > ret ) ret = num;
}


void buildWall(int cnt, pair<int, int> lastWallPos)
{
	if ( cnt == 3 )
	{
		bfs();
		return;
	}

	for ( int y = lastWallPos.first; y < n; y++ )
	{
		int x;
		if ( y == lastWallPos.first ) x = lastWallPos.second;
		else x = 0;
		for ( ; x < m; x++ )
		{
			if ( lab[y][x] == 1 || lab[y][x] == 2 ) continue;
			lab[y][x] = 1;
			buildWall(cnt + 1, make_pair(y, x));
			lab[y][x] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	for ( int y = 0; y < n; y++ )
	{
		for ( int x = 0; x < m; x++ )
		{
			cin >> lab[y][x];
			if ( lab[y][x] == 2 ) virusPos.push(make_pair(y, x));
		}
	}
	buildWall(0, make_pair(0, 0));
	cout << ret << '\n';
	return 0;
}