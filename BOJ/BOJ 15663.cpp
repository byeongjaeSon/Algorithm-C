#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums(10);
set<vector<int>> s1;
int n, m;

void solve(vector<int>& ret, int visited)
{
	if ( ret.size() == m )
		s1.insert(ret);

	for ( int i = 0; i < n; i++ )
	{
		if ( (visited & 1 << i) ) continue;
		ret.push_back(nums[i]);
		solve(ret, visited | 1 << i);
		ret.pop_back();
	}
}


int main()
{
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		cin >> nums[i];

	//sort(nums.begin(), nums.begin()+n);

	vector<int> ret;
	solve(ret, 0);

	for ( auto& v : s1 )
	{
		for ( auto& e : v )
			cout << e << " ";
		cout << '\n';
	}
	
	return 0;
}