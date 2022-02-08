#include <iostream>
#include <list>
using namespace std;

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		int n, k;
		cin >> n >> k;
		list<int> lt;
		for ( int i = 1; i <= n; i++ )
			lt.push_back(i);

		list<int>::iterator iter = lt.begin();
		while ( lt.size() > 2 )
		{
			iter = lt.erase(iter);
			if ( iter == lt.end() ) iter = lt.begin();
			for ( int i = 0; i < k - 1; i++ )
			{
				if ( ++iter == lt.end() ) iter = lt.begin();
			}
				
		}
		cout << lt.front() << " " << lt.back() << '\n';
	}
	return 0;
}