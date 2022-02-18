#include <iostream>
#include <string>
using namespace std;

char arr[1000001];
int pos = -1;

int main()
{
	string str, bombStr;
	cin >> str >> bombStr;
	
	int len = bombStr.length();
	for ( int i = 0; i < str.length(); i++ )
	{
		arr[++pos] = str[i];

		if ( str[i] == bombStr[len - 1] )
		{
			string M(arr + pos - len + 1, arr + pos + 1);
			if ( M == bombStr ) pos -= len;
		}
	}

	for ( int i = 0; i <= pos; i++ )
		cout << arr[i];
	
	if ( pos == -1 ) cout << "FRULA" << '\n';
	
	return 0;
}