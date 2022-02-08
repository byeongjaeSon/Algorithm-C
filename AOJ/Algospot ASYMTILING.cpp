#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int width)
{
	if ( width <= 1 ) return 1;

	int& ret = cache[width];
	if ( ret != -1 ) return ret;

	return ret = (tiling(width - 1)%MOD + tiling(width - 2)%MOD)%MOD;
}

int asymtiling(int width)
{
	if ( width % 2 == 1 )
		return (tiling(width) % MOD - tiling(width / 2)+ MOD) % MOD;

	int ret = tiling(width);
	ret = (ret % MOD - tiling((width - 2) / 2) % MOD + MOD) % MOD;
	ret = (ret % MOD - (tiling(width / 2)) % MOD + MOD) % MOD;

	return ret;
}

int main()
{
	int c, n;
	cin >> c;
	while ( c-- )
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << asymtiling(n) << '\n';
	}
	return 0;
}