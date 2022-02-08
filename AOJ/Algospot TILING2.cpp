#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int n)
{
	if ( n <= 1 ) return 1;
	
	int& ret = cache[n];
	if ( ret != -1 ) return ret;

	return ret = (tiling(n - 1) % MOD + tiling(n - 2) % MOD) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	while ( c-- )
	{
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;

		cout << tiling(n) << '\n';
	}
	return 0;
}