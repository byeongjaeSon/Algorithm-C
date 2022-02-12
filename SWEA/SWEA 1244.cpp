#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt;
string ret;

void solve(int pos, int cnt_, int n, string& number)
{
	int len = number.length();

	if ( pos == number.length() || cnt_ == n )
	{
		if ( number > ret )
		{
			ret = number;
			cnt = cnt_;
		}
		return;
	}

	int largest = pos;
	for ( int i = pos + 1; i < len; i++ )
		if ( number[largest] < number[i] ) largest = i;

	if ( largest == pos )
		solve(pos + 1, cnt_, n, number);
	else
	{
		for ( int i = pos + 1; i < len; i++ )
		{
			if ( number[i] == number[largest] )
			{
				swap(number[pos], number[i]);
				solve(pos + 1, cnt_ + 1, n, number);
				swap(number[i], number[pos]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;
	for ( int tc = 1; tc <= t; tc++ )
	{
		ret = "0"; cnt = 0;
		string number;
		cin >> number >> n;
		int len = number.length();
		
		solve(0, 0, n, number);
		
		int remain = n - cnt;
		if ( remain > 0 && remain & 1 && len > 1 )
		{
			bool duplicate = false;
			for ( int i = 0; i < len; ++i )
				for ( int j = i + 1; j < len; ++j )
					if ( number[i] == number[j] ) duplicate = true;

			if ( !duplicate )
				swap(ret[len - 1], ret[len - 2]);
		}

		cout << "#" << tc << " " << ret << '\n';
	}
	return 0;
}