#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int MAX_N = 100001;
int parent[MAX_N];

int findSet(int v)
{
	if ( v == parent[v] ) return v;
	return parent[v] = findSet(parent[v]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ )
		parent[i] = i;

	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;

	for ( int i = 0; i < m; i++ )
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		pq.push(make_pair(cost, make_pair(u, v)));
	}

	
	int selectCnt = 0;
	int sumCost = 0;

	while ( !pq.empty() )
	{
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if ( findSet(u) == findSet(v) ) continue;
		parent[findSet(u)] = findSet(v);

		sumCost += cost;
		if ( ++selectCnt == n - 2 ) break;
	}

	cout << sumCost << '\n';

	return 0;
}