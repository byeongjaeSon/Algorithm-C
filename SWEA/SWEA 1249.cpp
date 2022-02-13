#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[100][100];
int minCost[100][100];

const int INF = 987654321;
int n;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int solve(int y, int x)
{
	bool visited[100][100] = { false };
	priority_queue < pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(make_pair(0, make_pair(y, x)));
	visited[y][x] = true;

	while ( !pq.empty() )
	{
		int cost = pq.top().first;
		pair<int, int> currPos = pq.top().second;
		pq.pop();


		if ( cost > minCost[currPos.first][currPos.second] ) continue;

		for ( int direction = 0; direction < 4; ++direction )
		{
			int nextY = currPos.first + dy[direction];
			int nextX = currPos.second + dx[direction];

			if ( nextY < 0 || nextY >= n || nextX < 0 || nextX >= n ) continue;


			if ( minCost[nextY][nextX] > minCost[currPos.first][currPos.second] + map[nextY][nextX] )
			{
				minCost[nextY][nextX] = minCost[currPos.first][currPos.second] + map[nextY][nextX];
				pq.push(make_pair(cost, make_pair(nextY, nextX)));
			}	
		}
	}

	return minCost[n - 1][n - 1];
}


int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> n;
		for ( int i = 0; i < n; ++i )
			for ( int j = 0; j < n; ++j )
			{
				scanf("%1d", &map[i][j]);
				minCost[i][j] = INF;
			}
		
		minCost[0][0] = 0;
		
		printf("#%d %d\n", tc, solve(0, 0));
	}
	return 0;
}