#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[101][101];
string W, fileName;


//int checkMatchedFile(int w, int s)
//{
//	if ( w >= W.size() && s >= fileName.size() ) return 1;
//	else if ( w < W.size() && s >= fileName.size() )
//	{
//		for ( ; w < W.size(); w++ )
//			if ( W[w] != '*' ) return false;
//		return true;
//	}
//	else if ( w >= W.size() && s < fileName.size() ) return 0;
//
//
//	int& ret = cache[w][s];
//	if ( ret != -1 ) return ret;
//
//	if ( W[w] == '*' )
//		for ( int coverSize = 0; coverSize <= fileName.size(); coverSize++ )
//			ret = max(ret, checkMatchedFile(w + 1, s + coverSize));
//	else if ( W[w] == '?' || W[w] == fileName[s] )
//		ret = checkMatchedFile(w + 1, s + 1);
//	else  ret = 0;
//
//	return ret;
//}

bool checkMatchedFile(int w, int s)
{
	int& ret = cache[w][s];
	if ( ret != -1 ) return ret;

	if ( w < W.size() && s < fileName.size() && (W[w] == '?' || W[w] == fileName[s]) )
		return ret = checkMatchedFile(w + 1, s + 1);

	if ( w == W.size() ) return (s == fileName.size());

	if ( W[w] == '*' )
		if (checkMatchedFile(w+1, s) || (s < fileName.size() && checkMatchedFile(w, s+1)))
			return ret = 1;
		
	return ret = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	while ( c-- )
	{
		vector<string> matchedNames;
		int n;
		cin >> W >> n;
		while ( n-- )
		{
			memset(cache, -1, sizeof(cache));
			cin >> fileName;
			if ( checkMatchedFile(0, 0) == 1 )  matchedNames.push_back(fileName);
		}
		sort(matchedNames.begin(), matchedNames.end());
		for ( string& name : matchedNames ) cout << name << '\n';
	}
	return 0;
}