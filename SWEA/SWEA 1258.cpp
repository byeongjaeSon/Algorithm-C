#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void solve(int n, int map[100][100], vector<pair<int, pair<int, int>>>& result, pair<int, int> prevPos)
{
	pair<int, int> firstPos = prevPos;
	bool flag = false;
	int i, j;
	for ( i = firstPos.first; i < n; ++i )
	{
		for ( j = 0; j < n; ++j )
		{
			if ( map[i][j] != 0 )
			{
				firstPos.first = i; // Y
				firstPos.second = j; // X
				flag = true;
				break;
			}
		}
		if ( flag == true ) break;
	}
	if ( i == n ) return;

	int endY = firstPos.first;
	int endX = firstPos.second;

	while ( endY < n && map[endY][firstPos.second] != 0 ) ++endY;
	while ( endX < n && map[firstPos.first][endX] != 0 ) ++endX;

	int height = endY - firstPos.first;
	int width = endX - firstPos.second;
	result.push_back(make_pair(height * width, make_pair(height, width)));

	for ( int y = firstPos.first; y < endY; ++y )
		for ( int x = firstPos.second; x < endX; ++x )
			map[y][x] = 0;

	solve(n, map, result, firstPos);
	return;
}


int main()
{
	int map[100][100];
	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		int n;
		cin >> n;
		for ( int i = 0; i < n; ++i )
			for ( int j = 0; j < n; ++j )
				cin >> map[i][j];

		vector<pair<int, pair<int, int>>> result;

		solve(n, map, result, { 0,0 });
		sort(result.begin(), result.end());
		cout << "#" << tc << " " << result.size() << " ";
		for ( auto e : result )
			cout << e.second.first << " " << e.second.second << " ";
		cout << '\n';
	}
	return 0;
}