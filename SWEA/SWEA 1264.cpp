#include <iostream>
#include <string>
using namespace std;

int cache[500][500];
string str1, str2;
int len;

int solve(int pos1, int pos2)
{
	if ( pos1 == len - 1 || pos2 == len - 1 )
	{
		if ( str1[pos1] == str2[pos2] ) return 1;
		else return 0;
	}

	int& ret = cache[pos1][pos2];
	if ( ret != -1 ) return ret;

	if ( str1[pos1] == str2[pos2] )
		ret = 1 + solve(pos1 + 1, pos2 + 1);
	else
		ret = max(solve(pos1 + 1, pos2), solve(pos1, pos2 + 1));

	return ret;
}

int main()
{
	int t;
	cin >> t;

	for ( int tc = 1; tc <= t; ++tc )
	{
		memset(cache, -1, sizeof(cache));
		cin >> len >> str1 >> str2;
		
		double result = (solve(0, 0) / (double)len) * 100;
		cout << fixed;
		cout.precision(2);
		cout << "#" << tc << " " << result << '\n';
	}
	return 0;
}