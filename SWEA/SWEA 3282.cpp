#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int volume[101], need[101], cache[1001][101];
int n, k;

int solve(int capacity, int item)
{
	if ( n + 1 == item )
		return 0;

	int& ret = cache[capacity][item];
	if ( ret != -1 ) return ret;

	if ( capacity < volume[item] )
		ret = solve(capacity, item + 1);
	else
		ret = max(solve(capacity, item + 1), solve(capacity - volume[item], item + 1) + need[item]);

	return ret;
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
		memset(cache, -1, sizeof(cache));
		cin >> n >> k;
		for ( int i = 0; i < n; i++ )
			cin >> volume[i+1] >> need[i+1];
	
		cout << "#" << tc << " " << solve(k, 1) << '\n';
	}
	return 0;
}