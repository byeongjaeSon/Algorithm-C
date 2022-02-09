#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string club;
const int MOD = 1000000007;
const int MAX_DAY = 10001;

int dp[MAX_DAY][17];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		memset(dp, 0, sizeof(dp));
		cin >> club;
		int days = club.length();
		for ( int day = 0; day < days; day++ )
		{
			int admin = 1 << (club[day] - 'A');
			for ( int today = 1; today <= 16; today++ )
			{
				if ( day == 0 )
				{
					if ( (today & admin) != 0 && (today & 1) != 0 ) 
						dp[day][today] = 1;
				}
				else
				{
					for ( int yesterday = 1; yesterday <= 16; yesterday++ )
					{
						if ( (yesterday & today) != 0 && (today & admin) != 0 )
							dp[day][today] = (dp[day][today] % MOD + dp[day - 1][yesterday] % MOD) % MOD;
					}
				}
			}
		}

		int sum = 0;
		for ( int i = 1; i <= 16; i++ )
			sum = (sum%MOD + dp[days-1][i]%MOD)%MOD;

		cout << "#" << test_case << " " << sum << '\n';
	}
	return 0;
}