#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main()
{
	int n;
	cin >> n;

	vector<ull> dist(n), cost(n);
	for ( int i = 0; i < n-1; i++ )
		cin >> dist[i];
	dist[n - 1] = 0;

	for ( int i = 0; i < n; i++ )
		cin >> cost[i];

	int nowTown = 0;
	ull result = 0;

	while ( nowTown <= n - 1 )
	{
		ull currCost = cost[nowTown];
		ull totalDist = 0;

		while ( nowTown < n && currCost <= cost[nowTown] )
			totalDist += dist[nowTown++];

		result += totalDist * currCost;
	}

	cout << result << '\n';
	return 0;
}