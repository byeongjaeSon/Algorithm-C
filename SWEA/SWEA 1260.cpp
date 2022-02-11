#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 987564321;

void findMatrix(int n, int map[100][100], vector<pair<int, int>>& result, pair<int, int> prevPos)
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
	result.push_back(make_pair(height, width));

	for ( int y = firstPos.first; y < endY; ++y )
		for ( int x = firstPos.second; x < endX; ++x )
			map[y][x] = 0;

	findMatrix(n, map, result, firstPos);
	return;
}

bool findSeq(vector<pair<int, int>>& result, vector<pair<int, int>>& seq, vector<bool>& visited)
{
	if ( seq.size() == result.size() ) return true;

	for ( int i = 0; i < result.size(); ++i )
	{
		if ( visited[i] ) continue;

		if ( seq.empty() )
		{
			visited[i] = true;
			seq.push_back(result[i]);
			if ( findSeq(result, seq, visited) ) return true;
			seq.pop_back();
			visited[i] = false;
		}
		else
		{
			if ( seq.back().second == result[i].first )
			{
				visited[i] = true;
				seq.push_back(result[i]);
				if ( findSeq(result, seq, visited) ) return true;
				seq.pop_back();
				visited[i] = false;
			}
		}
	}
	return false;
}

int solve(int s, int e, vector<pair<int, int>>& matrix, int cache[20][20])
{
	int& ret = cache[s][e];
	if ( ret != -1 ) return ret;

	if ( s == e ) return ret = 0;
	if ( s + 1 == e ) return ret = matrix[s].first * matrix[s].second * matrix[e].second;

	ret = INF;
	for ( int k = s; k < e; ++k )
		ret = min(ret, solve(s, k, matrix, cache) + solve(k + 1, e, matrix, cache) + matrix[s].first * matrix[k].second * matrix[e].second);

	return ret;
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

		vector<pair<int, int>> result;
		findMatrix(n, map, result, { 0,0 });

		vector<bool> visited(result.size(), false);
		vector<pair<int, int>> seq;
		findSeq(result, seq, visited);

		int cache[20][20];
		memset(cache, -1, sizeof(cache));

		cout << "#" << tc << " " << solve(0, seq.size()-1, seq, cache) << '\n';
	}
	return 0;
}