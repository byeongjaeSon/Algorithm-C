#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> pos;
int n;


int getMinDist()
{
	sort(pos.begin() + 1, pos.end() - 1);
	int ret = 987654321;

	do
	{
		int dist = 0;
		for ( int i = 0; i < pos.size() - 1; i++ )
			dist += abs(pos[i].first - pos[i + 1].first) + abs(pos[i].second - pos[i + 1].second);
		ret = min(ret, dist);
	}
	while ( next_permutation(pos.begin() + 1, pos.end() - 1) );

	return ret;
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		cin >> n;

		pos.clear();
		int workY, workX;
		int homeY, homeX;
		cin >> workY >> workX >> homeY >> homeX;
		pos.push_back(make_pair(workY, workX));
		for ( int i = 0; i < n; i++ )
		{
			int y, x;
			cin >> y >> x;
			pos.push_back(make_pair(y, x));
		}
		pos.push_back(make_pair(homeY, homeX));

		cout << "#" << test_case << " " << getMinDist() << '\n';
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}