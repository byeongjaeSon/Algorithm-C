#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

// [s, e)
void solve(int s, int e)
{
	if ( s >= e ) return;
	if ( s + 1 == e )
	{
		cout << nums[s] << '\n';
		return;
	}

	int idx;
	for ( idx = s + 1; idx < e; idx++ )
		if ( nums[s] < nums[idx] ) break;
	
	solve(s + 1, idx);
	solve(idx, e);
	cout << nums[s] << '\n';
}

int main()
{	
	//freopen("input.txt", "r", stdin);
	while ( 1 )
	{
		int num;
		cin >> num;
		if ( cin.eof() ) break;
		nums.push_back(num);
	}

	solve(0, nums.size());
	return 0;
}