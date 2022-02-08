#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	if ( b < a ) swap(a, b);
	if ( a == b ) cout << 0 << '\n';
	else
	{
		cout << b - a - 1 << '\n';
		for ( long long num = a + 1; num < b; num++ )
			cout << num << ' ';
	}
}