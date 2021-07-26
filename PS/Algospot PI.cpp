#include <iostream>
#include <cstring>
using namespace std;

int cache[10000];
const int INF = 987654321;
string text;

bool isAllSameNumber(const string& S)
{
	for ( int i = 0; i + 1 < S.length(); i++ )
		if ( S[i + 1] != S[i] ) return false;
	return true;
}

bool isMonotonousChange(const string& S)
{
	int standard = S[1] - S[0];
	if ( S[1] > S[0] )
	{
		for ( int i = 1; i < S.length(); i++ )
			if ( S[i] - S[i-1] != 1 ) return false;
	}
	else 
	{
		for ( int i = 1; i < S.length(); i++ )
			if ( S[i] - S[i-1] != -1 ) return false;
	}
	
	return true;
}

bool doTakenTurns(const string& S)
{
	for ( int i = 0; i + 2 < S.length(); i += 2 )
		if ( S[i + 2] != S[i] ) return false;
	for ( int i = 1; i + 2 < S.length(); i += 2 )
		if ( S[i + 2] != S[i] ) return false;
	return true;
}

bool isArithmeticalSequence(const string& S)
{
	int standard = S[1] - S[0];
	for ( int i = 1; i + 1 < S.length(); i++ )
		if ( S[i + 1] - S[i] != standard ) return false;
	return true;
}

int calDifficulty(const string& S)
{
	int difficulty = 0;
	if ( isAllSameNumber(S) ) difficulty = 1;
	else if ( isMonotonousChange(S) ) difficulty = 2;
	else if ( doTakenTurns(S) ) difficulty = 4;
	else if ( isArithmeticalSequence(S) ) difficulty = 5;
	else difficulty = 10;

	return difficulty;
}

// solve(start) : start부터 시작하는 text 난이도의 최솟값.
int solve(int start)
{
	if ( text.length() - start <= 2 ) return INF;
	if ( text.length() - start <= 5 ) return calDifficulty(text.substr(start, text.length() - start));

	int& ret = cache[start];
	if ( ret != INF ) return ret;

	for ( int delta = 3; delta <= 5; delta++ )
		ret = min(ret, calDifficulty(text.substr(start,delta)) + solve(start + delta));

	return ret;
}


int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		for ( int i = 0; i < 10000; i++ )
			cache[i] = INF;
		cin >> text;
		cout << solve(0) << '\n';
	}
	return 0;
}
