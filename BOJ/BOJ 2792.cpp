#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> v;
int n, m;
long long getPairs(long long mid)
{
	long long cnt = 0;
	for ( int& e : v )
	{
		cnt += e / mid;
		if ( e % mid > 0 ) cnt++;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	long long maxNum = 0;
	for ( int i = 0; i < m; i++ )
	{
		int num;
		cin >> num;
		v.push_back(num);
		if ( maxNum < num ) maxNum = num;
	}

	long long ret = LLONG_MAX;
	long long lo = 1, hi = maxNum;
	while ( lo <= hi )
	{
		long long mid = (lo + hi) / 2;

		long long cnt = getPairs(mid);
		if ( cnt <= n ) // 이때, 보석을 받지 못하는 학생이 있어도 된다.
		{
			ret = min(ret, mid);
			hi = mid - 1;
		}	
		else
			lo = mid + 1;
	}

	cout << ret << '\n';
	return 0;
}