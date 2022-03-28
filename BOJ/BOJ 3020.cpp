#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, h;
	cin >> n >> h;

	vector<int> blocks(h, 0);
	vector<int> lo(h, 0), hi(h, 0);

	for ( int i = 0; i < n; i++ )
	{
		int height;
		cin >> height;

		if ( i & 1 ) hi[h - height]++;
		else lo[height - 1]++;
	}

	int sum = 0;
	for ( int i = h - 1; i >= 0; i-- )
	{
		sum += lo[i];
		blocks[i] += sum;
	}
	sum = 0;
	for ( int i = 0; i < h; i++ )
	{
		sum += hi[i];
		blocks[i] += sum;
	}

	sort(blocks.begin(), blocks.end());
	int minBlocks = blocks[0];
	cout << minBlocks << " " << upper_bound(blocks.begin(), blocks.end(), minBlocks) - lower_bound(blocks.begin(), blocks.end(), minBlocks);

	return 0;
}

