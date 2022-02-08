#include <bits/stdc++.h>
using namespace std;

int N, Y, M;
int arr[20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for ( int i = 0; i < N; i++ ) cin >> arr[i];

	for ( int i = 0; i < N; i++ )
	{
		Y += ((arr[i] / 30) + 1) * 10;
		M += ((arr[i] / 60) + 1) * 15;
	}

	if ( Y < M ) cout << "Y " << Y;
	else if ( Y > M ) cout << "M " << M;
	else cout << "Y M " << Y;
}