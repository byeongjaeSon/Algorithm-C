#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int INF = 987654321;
int map[12][12];
vector<pair<int, int>> v;
int cost = INF, n, coreNum = 0;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void solve(int cost_, int coreNum_)
{
	if ( coreNum_ + v.size() < coreNum ) return;

	if ( v.empty() )
	{
		if ( coreNum < coreNum_ )
		{
			coreNum = coreNum_;
			cost = cost_;
		}
		else if ( coreNum == coreNum_ )
			cost = min(cost, cost_);

		return;
	}

	pair<int, int> currPos = v.back();

	if ( currPos.first == 0 || currPos.first == n - 1 || currPos.second == 0 || currPos.second == n - 1 )
	{
		v.pop_back();
		solve(cost_, coreNum_ + 1);
		v.push_back(currPos);

		return;
	}

	for ( int direction = 0; direction < 4; direction++ )
	{
		bool isCovered = false;

		pair<int, int> nextPos = currPos;
		nextPos.first += dy[direction];
		nextPos.second += dx[direction];

		while ( nextPos.first >= 0 && nextPos.first < n && nextPos.second >= 0 && nextPos.second < n )
		{
			if ( map[nextPos.first][nextPos.second] != 0 )
			{
				isCovered = true;
				break;
			}
			nextPos.first += dy[direction];
			nextPos.second += dx[direction];
		}

		if ( !isCovered )
		{
			nextPos = currPos;
			nextPos.first += dy[direction];
			nextPos.second += dx[direction];
			int sum = 0;
			while ( nextPos.first >= 0 && nextPos.first < n && nextPos.second >= 0 && nextPos.second < n )
			{
				++sum;
				++map[nextPos.first][nextPos.second];
				nextPos.first += dy[direction];
				nextPos.second += dx[direction];
			}

			v.pop_back();
			solve(cost_ + sum, coreNum_ + 1);
			v.push_back(currPos);

			nextPos = currPos;
			nextPos.first += dy[direction];
			nextPos.second += dx[direction];
			while ( nextPos.first >= 0 && nextPos.first < n && nextPos.second >= 0 && nextPos.second < n )
			{
				--map[nextPos.first][nextPos.second];
				nextPos.first += dy[direction];
				nextPos.second += dx[direction];
			}
		}
		else
		{
			v.pop_back();
			solve(cost_, coreNum_);
			v.push_back(currPos);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		v = {};
		cin >> n;
		cost = INF, coreNum = 0;
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < n; j++ )
			{
				cin >> map[i][j];
				if ( map[i][j] == 1 )
					v.push_back(make_pair(i, j));
			}
		}

		solve(0, 0);

		cout << "#" << tc << " " << cost << '\n';
	}
	return 0;
}