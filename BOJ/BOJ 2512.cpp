#include <iostream>
#include <vector>
using namespace std;

int n, m, maxVal;
vector<int> budget;

bool check(int mid)
{
	int sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		if ( budget[i] <= mid ) sum += budget[i];
		else sum += mid;
	}
	if ( sum <= m ) return true;
	else return false;
}

int main()
{
	cin >> n;
	budget.resize(n);
	int sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		cin >> budget[i];
		sum += budget[i];
		if ( maxVal < budget[i] ) maxVal = budget[i];
	}
	cin >> m;
	if ( sum <= m ) cout << maxVal << '\n';
	else
	{
		long long low = 0, high = maxVal;
		// 상한액이 low인 경우, 국가 예산으로 충당가능.
		// 상한액이 high인 경우, 국가 예산이 부족.
		while ( low + 1 < high )
		{
			long long mid = (low + high) / 2;
			if ( check(mid) ) low = mid;
			else high = mid;
		}
		cout << low << '\n';
	}
	return 0;
}