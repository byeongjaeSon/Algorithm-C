#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<int>& heights, int left, int right)
{
	if ( left == right ) return heights[left];

	int mid = (left + right) / 2;
	int ret = max(solve(heights, left, mid), solve(heights, mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(heights[lo], heights[hi]);
	ret = max(ret, 2 * height);
	while ( left < lo || hi < right )
	{
		if ( hi < right && (left == lo || heights[lo - 1] < heights[hi + 1]) )
		{
			++hi;
			height = min(height, heights[hi]);
		}
		else
		{
			--lo;
			height = min(height, heights[lo]);
		}
		ret = max(ret, height * (hi-lo+1));
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{
		int n;
		cin >> n;
		vector<int> heights(n);
		for ( int i = 0; i < n; i++ ) cin >> heights[i];
		cout << solve(heights, 0, n - 1) << '\n';
	}
	return 0;
}