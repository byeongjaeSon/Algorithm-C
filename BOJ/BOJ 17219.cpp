#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	map<string,string> memo;

	for ( int i = 0; i < m; i++ )
	{
		string url, password;
		cin >> url >> password;
		memo.insert(make_pair(url, password));
	}

	for ( int i = 0; i < n; i++ )
	{
		string url;
		cin >> url;
		cout << memo[url] << '\n';
	}

	return 0;
}