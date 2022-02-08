#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ret = 0, freq1[26] = { }, freq2[26] = { };
	string str1, str2;
	cin >> str1 >> str2;
	for ( char ch : str1 ) freq1[ch - 'a']++;
	for ( char ch : str2 ) freq2[ch - 'a']++;
	
	for ( int i = 0; i < 26; i++ )
		ret += abs(freq1[i] - freq2[i]);
	
	cout << ret;
}