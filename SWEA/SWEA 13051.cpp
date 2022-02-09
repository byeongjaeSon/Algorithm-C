#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for ( int tc = 1; tc <= t; ++tc )
	{
		list<int> seq;
		int n, m, l;
		cin >> n >> m >> l;
		for ( register int i = 0; i < n; ++i )
		{
			register int num;
			cin >> num;
			seq.push_back(num);
		}

		for ( register int i = 0; i < m; ++i )
		{
			char cmd;
			cin >> cmd;

			if ( cmd == 'I' )
			{
				register int pos, num;
				cin >> pos >> num;

				list<int>::iterator iter = seq.begin();
				advance(iter, pos);
				seq.insert(iter, num);
			}
			else if ( cmd == 'D' )
			{
				register int pos;
				cin >> pos;
				list<int>::iterator iter = seq.begin();
				advance(iter, pos);

				seq.erase(iter);
			}
			else
			{
				register int pos, num;
				cin >> pos >> num;

				list<int>::iterator iter = seq.begin();
				advance(iter, pos);

				*iter = num;
			}
		}

		if ( l < seq.size() )
		{
			list<int>::iterator iter = seq.begin();
			advance(iter, l);
			cout << "#" << tc << " " << *iter << '\n';
		}
		else
			cout << "#" << tc << " " << -1 << '\n';
		
	}
	return 0;
}