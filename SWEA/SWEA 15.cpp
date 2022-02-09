#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1200002

bool studied[MAX];
int seq[MAX];
int cost[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;888
	cin >> tc;
	for ( int t = 1; t <= tc; t++ )
	{
		memset(studied, false, sizeof(studied));
		memset(seq, 0, sizeof(seq));
		memset(cost, 0, sizeof(cost));

		int n, p;
		int maxSeq = 0;
		cin >> n >> p;
		for ( int i = 0; i < n; i++ )
		{
			int day;
			cin >> day;
			studied[day] = true;
		}

		if ( studied[0] )
			seq[0] = 1;
		
		for ( int i = 1; i < MAX; i++ )
		{
			if ( studied[i] )
			{
				seq[i] = seq[i - 1] + 1;;
				cost[i] = cost[i - 1];
			}
			else
			{
				if ( cost[i - 1] + 1 <= p && seq[i-1] > 0)
				{
					seq[i] = seq[i - 1] + 1;
					cost[i] = cost[i - 1] + 1;
				}
				else
				{
					cost[i] = seq[i] = 0;
				}
			}
			maxSeq = max(maxSeq, seq[i]);
		}
		cout << "#" << t << " " << maxSeq << '\n';
	}
	return 0;
}