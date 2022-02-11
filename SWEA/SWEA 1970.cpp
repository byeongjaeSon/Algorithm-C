#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		vector<int> won = { 50000,10000,5000,1000,500,100,50,10 };
		vector<int> cnt(8, 0);

		int change;
		cin >> change;

		for ( int i = 0; i < 8; ++i )
		{
			int cal = change / won[i];
			if ( cal > 0 )
			{
				cnt[i] += cal;
				change %= won[i];
			}
		}
		cout << "#" << tc << '\n';
		for ( int& n : cnt ) cout << n << ' ';
		cout << '\n';
	}
	return 0;
}