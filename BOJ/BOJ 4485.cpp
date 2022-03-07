#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int cave[126][126];
int minCost[126][126];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n;
const int INF = 987654321;

int solve(int y, int x)
{

	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
	pq.push(make_pair(cave[0][0], make_pair(y, x)));

	while ( !pq.empty() )
	{
		int cost = pq.top().first;
		pair<int, int> currPos = pq.top().second;
		pq.pop();

		if ( cost > minCost[currPos.first][currPos.second] ) continue;

		for ( int direction = 0; direction < 4; direction++ )
		{
			int nextY = currPos.first + dy[direction];
			int nextX = currPos.second + dx[direction];

			if ( nextX < 0 || nextX >= n || nextY < 0 || nextY >= n ) continue;

			if ( minCost[nextY][nextX] > minCost[currPos.first][currPos.second] + cave[nextY][nextX] )
			{
				minCost[nextY][nextX] = minCost[currPos.first][currPos.second] + cave[nextY][nextX];
				pq.push(make_pair(minCost[nextY][nextX], make_pair(nextY, nextX)));
			}
		}

	}

	return minCost[n - 1][n - 1];
}

int main()
{
	int cnt = 1;
	while ( 1 )
	{
		cin >> n;
		if ( n == 0 ) break;

		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
			{
				cin >> cave[i][j];
				minCost[i][j] = INF;
			}
		minCost[0][0] = cave[0][0];

		cout << "Problem " << cnt << ": " << solve(0, 0) << '\n';
		cnt++;
	}
	return 0;
}