#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, num, v;
	cin >> N;
	int freq[201] = { };
	for ( int i = 0; i < N; i++ )
	{
		cin >> num;
		freq[num + 100]++;
	}
	cin >> v;
	cout << freq[v + 100];
}