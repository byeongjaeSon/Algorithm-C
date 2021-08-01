#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <utility>
#include <cstring>
using namespace std;

int n, cnt, sharkSize = 2;
int space[20][20];
bool visited[20][20];
const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,-1,0,1 };

int bfs(pair<int, int> curr)
{
	queue<pair<int, int>> q;
	q.push(curr);
	visited[curr.first][curr.second] = true;
	int time = 0, level = 0;
	while ( !q.empty() )
	{
		level++;
		int qSize = q.size();
		vector<pair<int, int>> v;
		for ( int i = 0; i < qSize; i++ )
		{
			curr = q.front();
			q.pop();
			for ( int direction = 0; direction < 4; direction++ )
			{
				int nextY = curr.first + dy[direction];
				int nextX = curr.second + dx[direction];
				if ( nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1 || space[nextY][nextX] > sharkSize ) continue;
				if ( !visited[nextY][nextX] )
				{
					if ( space[nextY][nextX] < sharkSize && space[nextY][nextX] != 0 ) v.push_back(make_pair(nextY, nextX));
					q.push(make_pair(nextY, nextX));
					visited[nextY][nextX] = true;
				}
			}
		}
		if ( !v.empty() )
		{
			sort(v.begin(), v.end());
			space[v[0].first][v[0].second] = 0;
			cnt++;
			if ( cnt == sharkSize )
			{
				cnt = 0;
				sharkSize++;
			}
			time += level;
			level = 0;
			queue<pair<int, int>> empty;
			swap(q, empty);
			q.push(v[0]);
			memset(visited, false, sizeof(visited));
			visited[v[0].first][v[0].second] = true;
		}
	}
	return time;
}

int main()
{
	cin >> n;
	pair<int, int> startPos;
	for ( int y = 0; y < n; y++ )
		for ( int x = 0; x < n; x++ )
		{
			cin >> space[y][x];
			if ( space[y][x] == 9 )
			{
				startPos = make_pair(y, x);
				space[y][x] = 0;
			}
		}
	cout << bfs(startPos) << '\n';
	return 0;
}