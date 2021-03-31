#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> num;

bool check(long long mid)
{
	int cnt = 0;
	long long sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		sum += num[i];
		if ( sum >= mid )
		{
			sum = 0;
			cnt++;
		}
	}
	if ( cnt >= k ) return true;
	else return false;
}

int main()
{
	cin >> n >> k;
	num.resize(n);

	for ( int i = 0; i < n; i++ )
		cin >> num[i];
	// 최소 점수가 lo면 k개 이상 그룹으로 나눌 수 있다. => 그룹끼리 합쳐 k개 그룹을 만들 수 있음.
	// 최소 점수가 hi면 k개의 그룹으로 나눌 수 없다.
	long long lo = 0, hi = *max_element(num.begin(), num.end()) * n + 1;
	while ( lo + 1 < hi )
	{
		long long mid = (lo + hi) / 2;
		if ( check(mid) ) lo = mid;
		else hi = mid;
	}
	cout << lo << '\n';
	return 0;
}