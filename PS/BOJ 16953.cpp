#include <iostream>
#include <queue>
using namespace std;

int bfs(long long a, long long b)
{
	queue<long long> q;
	q.push(a);
	int level = 0;
	while ( !q.empty() )
	{
		int qSize = q.size();
		for ( int i = 0; i < qSize; i++ )
		{
			long long curr = q.front();
			q.pop();
			if ( curr == b ) return level+1;
			if ( curr * 10 + 1 <= b ) q.push(curr * 10 + 1);
			if ( 2 * curr <= b ) q.push(2 * curr);
		}
		level++;
	}
	return -1;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	cout << bfs(a, b) << '\n';
	return 0;
}