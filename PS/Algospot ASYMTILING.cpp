#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000007

int cache[101];

int tiling(int width)
{
	if ( width <= 1 ) return 1;

	int& ret = cache[width];
	if ( ret != -1 ) return ret;
	return ret = (tiling(width - 1)%MOD + tiling(width - 2)%MOD)%MOD;
}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		
		// 전체 경우의 수 - 좌우 대칭인 경우의 수
		int whole = tiling(n);
		int sub = 0;
		if ( n % 2 == 1 ) sub = tiling((n - 1) / 2);
		else sub = (tiling(n / 2)%MOD + tiling((n - 2) / 2)%MOD)%MOD;

		int ret = (whole%MOD - sub%MOD + MOD)%MOD;
		cout << ret << '\n';
	}
	return 0;
}