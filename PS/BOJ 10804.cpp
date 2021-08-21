#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[21];
	for ( int i = 1; i < 21; i++ ) arr[i] = i;

	for ( int i = 0; i < 10; i++ )
	{
		int from, to;
		cin >> from >> to;
		for ( int j = 0; j <= (to - from) / 2; j++ )
			swap(arr[from + j], arr[to - j]);
	}
	for ( int i = 1; i < 21; i++ ) cout << arr[i] << ' ';
}