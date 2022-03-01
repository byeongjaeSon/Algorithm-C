#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unordered_map<int, bool> um;
	int n, m, key;
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> key;
		um[key] = true;
	}

	cin >> m;
	for ( int i = 0; i < m; i++ )
	{
		cin >> key;
		cout << um[key] << ' ';
	}
}