#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


bool checkMatchedFile(string W, string fileName)
{
	if ( W.empty() && !fileName.empty() ) return false;
	else if ( !W.empty() && fileName.empty() )
	{
		for ( auto ch : W )
			if ( ch != '*' ) return false;
		return true;
	}
	else if ( W.empty() && fileName.empty() ) return true;

	if ( W[0] == '?' )
		return checkMatchedFile(W.substr(1), fileName.substr(1));
	else if ( W[0] == '*' )
		return checkMatchedFile(W, fileName.substr(1)) || checkMatchedFile(W.substr(1), fileName.substr(1));
	else
	{
		if ( W[0] != fileName[0] ) return false;
		else return checkMatchedFile(W.substr(1), fileName.substr(1));
	}
}

int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{
		string W;
		vector<string> matchedNames;
		int n;

		cin >> W >> n;
		matchedNames.clear();
		while ( n-- )
		{
			string fileName;
			cin >> fileName;
			if ( checkMatchedFile(W, fileName) )  matchedNames.push_back(fileName);
		}
		sort(matchedNames.begin(), matchedNames.end());
		for ( string& name : matchedNames ) cout << name << '\n';
	}
	return 0;
}