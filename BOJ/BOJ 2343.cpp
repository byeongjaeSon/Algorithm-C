#include <iostream>
#include <vector>
using namespace std;

int n, m, maxVal;
vector<int> times;

bool check(int mid)
{
	int cnt = 1, sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		sum += times[i];
		if ( times[i] > mid ) return false;
		if ( sum > mid )
		{
			sum = times[i];
			cnt++;
		}
	}
	if ( cnt <= m ) return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	times.resize(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> times[i];
		maxVal += times[i];
	}
	// 블루레이 크기가 lo일 경우, m개의 블루레이로는 녹화 불가능
	// 블루레이 크기가 hi일 경우, m개의 블루레이로 녹화 가능
	int lo = 0, hi = maxVal;
	while ( lo + 1 < hi )
	{
		int mid = (lo + hi) / 2;
		if ( check(mid) ) hi = mid;
		else lo = mid;
	}
	cout << hi << '\n';
	return 0;
}