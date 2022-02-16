#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	string str;
	cin >> str;
	stack <char> s;

	unordered_map<char, int> m;
	m['*'] = m['/'] = 10;
	m['+'] = m['-'] = 1;
	int len = str.length();
	for ( int i = 0; i < len; i++ )
	{
		if ( 'A' <= str[i] && str[i] <= 'Z' )
			cout << str[i];
		else
		{
			if ( str[i] == ')' )
			{
				while ( !s.empty() && s.top() != '(' )
				{
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else if ( str[i] == '(' ) s.push(str[i]);
			else
			{
				while ( !s.empty() )
				{
					if ( m[s.top()] >= m[str[i]] )
					{
						cout << s.top();
						s.pop();
					}
					else break;
				}
				s.push(str[i]);
			}
		}
	}
	while ( !s.empty() )
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}