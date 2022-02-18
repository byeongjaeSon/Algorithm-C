#include <iostream>
#include <cstring>
using namespace std;

int cache1[1001];
int cache2[1001];
int arr[1001];
int n;

// lis(k) : k번째 원소를 끝으로 하는 LIS
int lis(int k)
{
	int& ret = cache1[k];
	if ( ret != -1 ) return ret;

	ret = 1;
	for ( int i = k-1; i >= 0; i-- )
		if ( arr[i] < arr[k] )
			ret = max(ret, 1 + lis(i));
	
	return ret;
}

// lds(k) : k번째 원소를 시작으로 하는 LDS
int lds(int k)
{
	int& ret = cache2[k];
	if ( ret != -1 ) return ret;

	ret = 1;
	for ( int i = k+1; i < n; i++ )
		if ( arr[k] > arr[i] )
			ret = max(ret, 1 + lds(i));

	return ret;
}

void bitonic()
{
	for ( int i = 0; i < n; i++ )
	{
		lis(i);
		lds(i);
	}
}

int main()
{
	memset(cache1, -1, sizeof(cache1));
	memset(cache2, -1, sizeof(cache2));

	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	bitonic();

	int maxVal = -1;
	for ( int i = 0; i < n; i++ )
		maxVal = max(maxVal, cache1[i] + cache2[i] - 1);

	cout << maxVal << '\n';
	return 0;
}