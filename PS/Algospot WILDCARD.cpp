#include <iostream>
using namespace std;

bool match(string& W, string& fileName, int w, int s)
{
	// base case;
	if ( w == W.length() && s == fileName.length() ) return true;
	else if ( w < W.length() && s >= fileName.length() )
	{
		for ( int i = w; i < W.length(); i++ )
			if ( W[i] != '*' ) return false;
		return true;
	}

	if ( W[w] != '*' )
	{
		if ( W[w] == '?' || W[w] == fileName[s] ) return match(W, fileName, w + 1, s + 1);
		else return false;
	}

	else return (match(W, fileName, w + 1, s + 1) || match(W, fileName, w, s + 1));

}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		string W;
		int n;
		cin >> W >> n;
		for ( int i = 0; i < n; i++ )
		{
			string fileName;
			cin >> fileName;
			if ( match(W, fileName, 0, 0) ) cout << fileName << endl;
		}
	}
	return 0;
}