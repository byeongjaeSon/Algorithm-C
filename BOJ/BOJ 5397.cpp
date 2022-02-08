#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L;
	string input;
	cin >> L;
	while ( L-- )
	{
		list<char> ret;
		auto cursor = ret.begin();
		cin >> input;
		for ( char cmd : input )
		{
			if ( cmd == '<' )
			{
				if ( cursor != ret.begin() ) cursor--;
			}
			else if ( cmd == '>' )
			{
				if ( cursor != ret.end() ) cursor++;
			}
			else if ( cmd == '-' )
			{
				if ( cursor != ret.begin() )
					cursor = ret.erase(--cursor);
			}
			else ret.insert(cursor, cmd);
		}
		for ( char e : ret ) cout << e;
		cout << '\n';
	}
}