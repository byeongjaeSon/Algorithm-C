#include <bits/stdc++.h>
using namespace std;

string res = "EABCD";
int ret, num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for ( int c = 0; c < 3; c++ )
	{
		ret = 4;
		for ( int i = 0; i < 4; i++ )
		{
			cin >> num;
			ret -= num;
		}
		cout << res[ret] << '\n';
	}
	return 0;
}