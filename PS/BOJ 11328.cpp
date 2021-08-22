#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string s1, s2;
		cin >> s1 >> s2;
		int freq1[26] = {};
		int freq2[26] = {};

		for ( char ch : s1 ) freq1[ch - 'a']++;
		for ( char ch : s2 ) freq2[ch - 'a']++;

		bool flag = true;
		for ( int i = 0; i < 26; i++ )
			if( freq1[i] != freq2[i] ) flag = false;
		if ( flag ) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
}