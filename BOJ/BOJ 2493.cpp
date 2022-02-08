#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> s;
	s.push({100000001,0});
	int n, height;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> height;
		while ( s.top().first < height )
			s.pop();
		cout << s.top().second << ' ';
		s.push({ height,i });
	}
}