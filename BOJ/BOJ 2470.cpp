#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100001];
const int INF = 2000000001;

int main()
{
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort(arr, arr + n);

	int s = 0, e = n-1, min = INF;
	int lo = s, hi = e;
	while ( s < e )
	{
		int tmp = arr[s] + arr[e];
		
		if ( min > abs(tmp) )
		{
			lo = s; hi = e; 
			min = abs(tmp);
			if ( tmp == 0 ) break;
		}
		
		if ( tmp < 0 ) s++;
		else e--;

	}

	cout << arr[lo] << " " << arr[hi] << '\n';
	return 0;
}