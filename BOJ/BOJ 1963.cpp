#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> primeNum;

int main()
{
	for ( int n = 1001; n < 10000; n += 2 )
	{
		bool isprime = true;
		for ( int k = 2; k * k <= n; k++ )
			if ( n % k == 0 ) isprime = false;
		if ( isprime ) primeNum.push_back(n);
	}

	int T, A, B;
	cin >> T;
	while ( T-- )
	{
		cin >> A >> B;
		if ( A == B )
		{
			cout << 0 << '\n';
			continue;
		}

		queue<int> q;
		vector<bool> visited(10000, false);
		q.push(A);
		visited[A] = true;

		int level = 0;
		bool flag = false;
		while ( !q.empty() )
		{
			int qSize = q.size();
			for ( int i = 0; i < qSize; i++ )
			{
				int curr = q.front();
				q.pop();
				if ( curr == B )
				{
					flag = true;
					break;
				}
				// 천의자리
				for ( int i = 1; i < 10; i++ )
				{
					int num = i * 1000 + curr % 1000;
					if ( !visited[num] && binary_search(primeNum.begin(), primeNum.end(), num) )
					{
						visited[num] = true;
						q.push(num);
					}
				}
				// 백의자리
				for ( int i = 0; i < 10; i++ )
				{
					int num = (curr / 1000) * 1000 + i * 100 + curr % 100;
					if ( !visited[num] && binary_search(primeNum.begin(), primeNum.end(), num) )
					{
						visited[num] = true;
						q.push(num);
					}
				}
				// 십의자리
				for ( int i = 0; i < 10; i++ )
				{
					int num = (curr / 100) * 100 + i * 10 + curr % 10;
					if ( !visited[num] && binary_search(primeNum.begin(), primeNum.end(), num) )
					{
						visited[num] = true;
						q.push(num);
					}
				}
				// 일의자리
				for ( int i = 1; i < 10; i += 2 )
				{
					int num = (curr / 10) * 10 + i;
					if ( !visited[num] && binary_search(primeNum.begin(), primeNum.end(), num) )
					{
						visited[num] = true;
						q.push(num);
					}
				}
			}
			if ( flag == true ) break;
			level++;
		}
		if ( flag == false ) cout << "Impossible" << '\n';
		else cout << level << '\n';
	}
	return 0;
}