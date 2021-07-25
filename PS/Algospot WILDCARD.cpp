#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[101][101];

string W, S;

bool matchMemoized(int w, int s)
{
	int& ret = cache[w][s];
	if ( ret != -1 ) return ret;

	if ( s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]) )
		return ret = matchMemoized(w + 1, s + 1);

	if ( w == W.size() ) return ret = (s == S.size());

	if ( W[w] == '*' )
	{
		if ( matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)) )
			return ret = 1;
	}
	return ret = 0;
}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		int n;
		cin >> W >> n;
		vector<string> answers;
		for ( int i = 0; i < n; i++ )
		{
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if ( matchMemoized(0, 0) ) answers.push_back(S);
		}
		sort(answers.begin(), answers.end());
		for ( string answer : answers ) cout << answer << '\n';
	}
	return 0;
}