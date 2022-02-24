#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; ++tc )
	{
		int n, cmd, num;
		cin >> n;
		
		pq = {};
;		cout << "#" << tc << " ";
		for ( int i = 0; i < n; i++ )
		{
			cin >> cmd;
			if ( cmd == 1 )
			{
				cin >> num;
				pq.push(num);
			}
			else
			{
				if ( !pq.empty() )
				{
					cout << pq.top() << " ";
					pq.pop();
				}
				else
				{
					cout << -1 << " ";
				}
			}
		}
		cout << '\n';
	}
	return 0;
}