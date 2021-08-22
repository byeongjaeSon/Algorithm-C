#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int freq[10] = { };
	int a, b, c, num;
	cin >> a >> b >> c;
	num = a * b * c;

	while ( num )
	{
		freq[num % 10]++;
		num /= 10;
	}
	
	for ( int e : freq ) cout << e << '\n';
}