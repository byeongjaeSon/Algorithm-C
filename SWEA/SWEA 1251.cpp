#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

pair<int, int> island[1000];
int parent[1000];
int n;
double e;

int findSet(int v)
{
	if ( parent[v] == v ) return v;
	else return findSet(parent[v]);
}

// 실행 시간 : 0.45247s
int main()
{
	freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> n;
		for ( int i = 0; i < n; ++i )
			cin >> island[i].first;
		for ( int i = 0; i < n; ++i )
			cin >> island[i].second;

		priority_queue<pair<long long, pair<int, int>>, vector< pair<long long, pair<int, int>>>, greater< pair<long long, pair<int, int>>>> pq;
		for ( int i = 0; i < n; ++i )
			for ( int j = i+1; j < n; ++j )
			{
				long long dx = (island[i].first - island[j].first);
				long long dy = (island[i].second - island[j].second);
				long long cost = dy * dy + dx * dx;
				pq.push(make_pair(cost, make_pair(i, j)));
			}

		cin >> e;

		// makeSet
		for ( int i = 0; i < n; ++i )
			parent[i] = i;

		int selectCnt = 0;
		long long sumCost = 0;
		while ( !pq.empty() )
		{
			int root1 = findSet(pq.top().second.first);
			int root2 = findSet(pq.top().second.second);
			long long cost = pq.top().first;

			pq.pop();
			if ( root1 == root2 ) continue;

			parent[root1] = root2; // unionSet

			sumCost += cost;
			if ( ++selectCnt == n - 1 ) break;
		}
		sumCost = round(e * sumCost);

		cout << "#" << tc << " " << sumCost << '\n';
	}
	return 0;
}