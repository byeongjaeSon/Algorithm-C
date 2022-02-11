#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


const int INF = 987654321;
int cache[501][501]; 
vector<pair<int, int>> matrix;
int n;

int solve(int s, int e)
{
	int& ret = cache[s][e];
	if ( ret != -1 ) return ret;

	if ( s == e ) return ret = 0;
	if ( s + 1 == e ) return ret = matrix[s].first * matrix[s].second * matrix[e].second;

	ret = INF;
	for ( int k = s; k < e; ++k )
		ret = min(ret, solve(s, k) + solve(k + 1, e) + matrix[s].first * matrix[k].second * matrix[e].second);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for ( int i = 0; i < n; ++i )
	{
		int r, c;
		cin >> r >> c;
		matrix.push_back(make_pair(r, c));
	}

	memset(cache, -1, sizeof(cache));
	
	cout << solve(0, matrix.size()-1) << '\n';
	
	return 0;
}