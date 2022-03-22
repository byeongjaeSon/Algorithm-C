#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[1000001];

int solve(int k)
{
	if ( k <= 1 ) return 0;

	int& ret = cache[k];
	if ( ret != -1 ) return ret;

	int v1 = solve(k - 1);

	if ( k % 3 == 0 )
		v1 = min(v1, solve(k / 3));
	if ( k % 2 == 0 )
		v1 = min(v1, solve(k / 2));
	
	return ret = v1 + 1;
}

int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));

	cout << solve(n) << '\n';
	return 0;
}