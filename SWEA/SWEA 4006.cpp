#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 50001;
int parent[MAX_N];

int findSet(int v) // path compression
{
	if ( parent[v] != v ) parent[v] = findSet(parent[v]);
	else return v;
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
		int n, m, s, e, c;
		cin >> n >> m;

		for ( register int i = 0; i < MAX_N; i++ )
			parent[i] = i;

		priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		for ( register int i = 0; i < m; i++ )
		{
			cin >> s >> e >> c;
			pq.push(make_pair(c, make_pair(s, e)));
		}


		register int selectCnt = 0, sumCost = 0;
		register int root1, root2, cost;
		for ( register int k = 0; k < m; k++ )
		{
			root1 = findSet(pq.top().second.first);
			root2 = findSet(pq.top().second.second);
			cost = pq.top().first;
			pq.pop();
			if ( root1 == root2 ) continue;

			parent[root1] = root2;

			sumCost += cost;
			if ( ++selectCnt == n - 1 ) break;
		}

		cout << "#" << tc << " " << sumCost << '\n';
	}
	return 0;
}