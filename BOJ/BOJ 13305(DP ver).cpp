#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
vector<ull> dist, cost, dp;

ull findMinCost(int nowTown)
{
	if ( nowTown == 0 ) return 0;
	if ( dp[nowTown] != -1 ) return dp[nowTown];

	ull result = ULLONG_MAX;
	for ( int prevTown = 0; prevTown < nowTown; prevTown++ )
	{
		ull totalDist = 0;
		for ( int i = prevTown; i < nowTown; i++ )
			totalDist +=  dist[i];

		result = min(result, findMinCost(prevTown) + (cost[prevTown] * totalDist));
	}

	return dp[nowTown] = result;
}

int main()
{
	int n;
	cin >> n;

	dp = vector<ull>(n, -1);
	dp[0] = 0;

	dist = vector<ull>(n);
	for ( int i = 0; i < n - 1; i++ )
		cin >> dist[i];
	dist[n - 1] = 0;

	cost = vector<ull>(n);
	for ( int i = 0; i < n; i++ )
		cin >> cost[i];

	cout << findMinCost(n - 1);

	return 0;
}