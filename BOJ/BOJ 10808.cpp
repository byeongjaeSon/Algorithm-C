#include <bits/stdc++.h>
using namespace std;

int main()
{
	int freq[26] = { 0, };
	string S;
	cin >> S;
	for ( char ch : S ) freq[ch - 'a']++;
	for ( int num : freq ) cout << num << ' ';
} 
