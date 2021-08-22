#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, freq[10] = { }, ans = 1;
	cin >> N;

	while ( N )
	{
		freq[N % 10]++;
		N /= 10;
	}

	for ( int i = 0; i < 10; i++ )
	{
		if ( i == 6 || i == 9 ) continue;
		ans = max(ans, freq[i]);
	}

	ans = max(ans, (freq[6] + freq[9] + 1) / 2);
	cout << ans;;
}