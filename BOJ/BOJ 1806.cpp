#include <iostream>

using namespace std;

int arr[100001];
const int INF = 987654321;

int main()
{
	int n, s;
	cin >> n >> s;
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int start = 0, end = 0, sum = 0, dist = INF;
	// [start, end) 
	while ( 1 )
	{
		if ( sum >= s )
		{
			dist = min(dist, end - start);
			sum -= arr[start++];
		}
		else if ( end == n ) break;	
		else sum += arr[end++];
		
	}
	if ( dist == INF ) cout << 0 << '\n';
	else cout << dist << '\n';
	return 0;
}