#include <iostream>
#include <climits>

using namespace std;

bool canMake(int cables[], int k, int n, long long length)
{
	int count = 0;

	for ( int i = 0; i < k; i++ )
	{
		count += cables[i] / length;
	}

	return count >= n;
}

int parametricSearch(int cables[], int k, int n)
{
	long long left = 1;
	long long right = INT_MAX;

	while ( left < right )
	{
		long long mid = (left + right + 1) / 2;

		if ( canMake(cables, k, n, mid) ) left = mid;
		else right = mid - 1;
	}
	return left;
}


int main()
{
	int k, n;
	int cables[10000];
	cin >> k >> n;

	for ( int i = 0; i < k; i++ )
		cin >> cables[i];

	cout << parametricSearch(cables, k, n);
	return 0;
}