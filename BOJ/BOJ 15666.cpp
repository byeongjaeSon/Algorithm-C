#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v, seq;
set<vector<int>> result;

void backtracking(int cnt, int next)
{
	if ( cnt == m )
	{
		result.insert(seq);
		return;
	}
	for ( int idx = next; idx < n; idx++ )
	{
		seq.push_back(v[idx]);
		backtracking(cnt + 1, idx);
		seq.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	v.resize(n);
	for ( int i = 0; i < n; i++ )
		cin >> v[i];
	sort(v.begin(), v.end());
	backtracking(0, 0);
	for ( set<vector<int>>::iterator iter = result.begin(); iter != result.end(); iter++ )
	{
		for ( int elem : *iter ) cout << elem << ' ';
		cout << '\n';
	}
	return 0;
}