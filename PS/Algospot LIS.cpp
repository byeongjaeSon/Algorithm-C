#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
// 완전 탐색 
int LIS(vector<int>& s, int last, int pos, int cnt)
{
	if ( pos == s.size() ) return cnt;
	int ret = 0;
	int ret2 = 0;
	if ( s[pos] > last )
		ret = max(LIS(s, s[pos], pos + 1, cnt + 1), LIS(s, last, pos + 1, cnt));
	else
		ret2 = LIS(s, last, pos + 1, cnt);
	return max(ret, ret2);
}

// 동적 계획법
int cache[500];
int LIS_ver2(vector<int>& s, int start) // LIS_ver2(start) = s[start]에서 시작하는 부분 증가 수열 중 최대의 길이
{
	int& ret = cache[start];
	if ( ret != -1 ) return ret;

	ret = 1;
	for ( int next = start + 1; next < n; next++ )
	{
		if ( s[start] < s[next] )
			ret = max(ret, LIS_ver2(s, next) + 1);
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		cin >> n;
		vector<int> s(n);
		for ( int i = 0; i < n; i++ )
			cin >> s[i];
		memset(cache, -1, sizeof(cache));
		//cout << LIS(s, -1, 0, 0) << '\n';

		int maxLen = 0;
		for ( int i = 0; i < n; i++ )
			maxLen = max(maxLen,LIS_ver2(s, i));
		
		cout << maxLen << '\n';
	}
	return 0;
}