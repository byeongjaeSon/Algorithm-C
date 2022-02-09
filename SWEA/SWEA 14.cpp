#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

#include <stdio.h>
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		vector<set<string>> v(51);
		int n;
		cin >> n;
		while ( n-- )
		{
			string name;
			cin >> name;
			v[name.size()].insert(name);
		}
		cout << "#" << test_case << '\n';
		for ( set<string>& s : v )
			for ( const string& n : s )
				cout << n << '\n';
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}