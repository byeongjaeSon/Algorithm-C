#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	register int test_case;

	for ( test_case = 1; test_case <= 10; ++test_case )
	{
		list<int> l;
		register int n;
		cin >> n;

		for ( register int i = 0; i < n; ++i )
		{
			register int num;
			cin >> num;
			l.push_back(num);
		}

		cin >> n;
		for ( register int i = 0; i < n; ++i )
		{
			char cmd;
			cin >> cmd;

			if ( cmd == 'I' )
			{
				register int x, y, s;
				cin >> x >> y;

				list<int> list2;

				for ( register int j = 0; j < y; ++j )
				{
					cin >> s;
					list2.push_back(s);
				}
				list<int>::iterator iter = l.begin();
				advance(iter, x);
				l.splice(iter, list2);
			}
			else if ( cmd == 'D' )
			{
				register int x, y;
				cin >> x >> y;

				list<int>::iterator iter1, iter2;
				iter1 = iter2 = l.begin();
				advance(iter1, x);
				advance(iter2, x + y);
				l.erase(iter1, iter2);
			}
			else
			{
				register int y, s;
				cin >> y;
				for ( register int j = 0; j < y; ++j )
				{
					cin >> s;
					l.push_back(s);
				}
			}

		}

		cout << "#" << test_case << " ";
		register int cnt = 1;
		for ( int& num : l )
		{
			cout << num << " ";
			if ( cnt == 10 ) break;
			++cnt;
		}
		cout << '\n';
	}
	return 0;
}