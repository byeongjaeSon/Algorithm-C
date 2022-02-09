#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solve(int cnt, int n, vector<int>& nums)
{
	int size = nums.size();

	if ( cnt == n )
	{
		int num = 0;
		for ( int i = 0; i < size; i++ )
			num += nums[i] * pow(10, size - i - 1);
		return num;
	}

	int ret = -1;
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = i + 1; j < size; j++ )
		{
			swap(nums[i], nums[j]);
			int candi = solve(cnt + 1, n, nums);
			ret = max(ret, candi);
			swap(nums[i], nums[j]);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; tc++ )
	{
		string number;
		cin >> number;
		
		int n;
		cin >> n;

		if ( number.length() == 1 )
		{
			cout << "#" << tc << " " << number << '\n';
			continue;
		}
		
		

		vector<int> nums;
		for ( int i = 0; i < number.size(); i++ )
			nums.push_back(number[i] - '0');


		int ret = 0;

		if ( nums.size()-1 <= n )
		{
			sort(nums.begin(), nums.end(), greater<>());

			if ( (n - nums.size() - 1) & 1 )
			{
				bool duplicate = false;
				for ( int i = 0; i < nums.size(); i++ )
				{
					for ( int j = i + 1; j < nums.size(); j++ )
					{
						if ( nums[i] == nums[j] )
						{
							duplicate = true;
							break;
						}
					}
				}
				if ( !duplicate ) swap(nums[nums.size() - 1], nums[nums.size() - 2]);
			}
			ret = solve(0, 0, nums);
		}
		else
			ret = solve(0, n, nums);

		if ( ret == -1 ) ret = stoi(number);
		cout << "#" << tc << " " << ret << '\n';
	}
	return 0;
}