#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, S, Y, ret = 0;
	int freq[6][2] = {};
	cin >> N >> K;
	for ( int i = 0; i < N; i++ )
	{
		cin >> S >> Y;
		freq[Y-1][S]++;
	}

	for ( int y = 0; y < 6; y++ )
		for ( int s = 0; s < 2; s++ )
			ret += ceil((freq[y][s] / (double)K));

	cout << ret;
}