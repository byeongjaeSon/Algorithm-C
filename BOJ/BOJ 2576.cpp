#include <bits/stdc++.h>
using namespace std;

int num, sum, min_odd = 99;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for ( int i = 0; i < 7; i++ )
	{
		cin >> num;
		if ( num % 2 == 1 )
		{
			if ( num < min_odd ) min_odd = num;
			sum += num;
		}
	}
	if ( sum == 0 ) cout << -1 << '\n';
	else cout << sum << '\n' << min_odd << '\n';
}