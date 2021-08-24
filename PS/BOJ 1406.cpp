#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<char> l;
	string str, cmd;
	int m;
	cin >> str;
	for ( char ch : str ) l.push_back(ch);
	auto iter = l.end();
	cin >> m;
	while ( m-- )
	{
		cin >> cmd;
		if ( cmd == "L" && iter != l.begin() ) iter--;
		else if ( cmd == "D" && iter != l.end() ) iter++;
		else if ( cmd == "B" && iter != l.begin() ) iter = l.erase(--iter);
		else if ( cmd == "P" )
		{
			char ch;
			cin >> ch;
			l.insert(iter, ch);
		}
	}
	for ( char i : l ) cout << i;
}