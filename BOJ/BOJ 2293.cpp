#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[10001];
vector<int> coins;
int minVal;


// cache[10] : 주어진 동전들로 10원을 만들수 있는 경우의 수
// 10 = 5 + 5 

int solve(int k)
{
	if ( k == 0 ) return 1;

	int& ret = cache[k];
	if ( ret != -1 ) return ret;

	ret = 0;
	for ( int& coin : coins )
	{
		if ( k % coin == 0 )
		{
			ret += solve(k - coin);
		}
			
	}
	return ret;
}


int solve2(int k)
{
	if ( k == 0 ) return 1;

	int& ret = cache[k];
	if ( ret != -1 ) return 1;

	ret = 0;
	for ( int& coin : coins )
	{
		if ( k % coin == 0 )
		{

			ret += solve(k - coin);
		}

	}
	return ret;
}


int main()
{
	int n, k;
	cin >> n >> k;

	for ( int i = 0; i < n; i++ )
	{
		int num;
		cin >> num;
		coins.push_back(num);
	}

	memset(cache, -1, sizeof(cache));

	cout << solve(k) << '\n';
	return 0;
}