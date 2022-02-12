#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str1, str2;
int cache[1001][1001];

int solve(int pos1, int pos2)
{
	if ( pos1 == -1 || pos2 == -1 ) return 0;
	
	int& ret = cache[pos1][pos2];
	if ( ret != -1 ) return ret;

	if ( str1[pos1] == str2[pos2] )
		ret = 1 + solve(pos1 - 1, pos2 - 1);
	else
		ret = max(solve(pos1 - 1, pos2), solve(pos1, pos2 - 1));
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> str1 >> str2;
		memset(cache, -1, sizeof(cache));
		cout << "#" << tc << " " << solve(str1.length()-1, str2.length()-1) << '\n';
	}
	return 0;
}