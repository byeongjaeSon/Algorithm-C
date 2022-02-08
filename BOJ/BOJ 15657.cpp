#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers, list;

void backtracking(int cnt, int idx)
{
	if ( cnt == m )
	{
		for ( int elem : list ) cout << elem << ' ';
		cout << '\n';
		return;
	}
	for ( int i = idx; i < numbers.size(); i++ )
	{
		list.push_back(numbers[i]);
		backtracking(cnt + 1, i);
		list.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	backtracking(0, 0);
	return 0;
}