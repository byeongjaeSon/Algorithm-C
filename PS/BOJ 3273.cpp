#include <bits/stdc++.h>
using namespace std;

int freq[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num, x, ret = 0;
	cin >> n;
	while ( n-- )
	{
		cin >> num;
		freq[num]++;
	}
	cin >> x;
	for ( int i = 1; i < (x + 1) / 2; i++ )
		if ( freq[i] && freq[x - i] ) ret++;
	cout << ret;
}