#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, height, ret = 0;
	stack<long long> heights;
	cin >> n;
	while ( n-- )
	{
		cin >> height;
		while ( !heights.empty() && heights.top() < height )
			heights.pop();
		ret += heights.size();
		heights.push(height);
	}
	cout << ret << '\n';
}