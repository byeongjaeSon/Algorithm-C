#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp
{
	bool operator() (const int a, const int b)
	{
		if ( abs(a) > abs(b) ) return true;
		else if ( abs(a) == abs(b) )
			if ( a > b ) return true;
		
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;

	int n, x;
	cin >> n;
	while ( n-- )
	{
		cin >> x;
		if ( x == 0 )
		{
			if ( pq.empty() ) cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}