#include <iostream>
#include <cstring>
using namespace std;

int seq[500], cache[501];
int c, n;

int solve(int k)
{
	int& ret = cache[k];
	if ( ret != -1 ) return ret;

	if ( k == 0 ) return 1;

	ret = 1;
	for ( int i = 0; i < k; i++ )
		if ( k == n || seq[i] < seq[k] )
			ret = max(ret, solve(i) + 1);
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c;
	while ( c-- )
	{
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for ( int i = 0; i < n; i++ )
			cin >> seq[i];
		cout << solve(n) - 1 << '\n';
	}
	return 0;
}