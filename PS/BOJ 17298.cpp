#include <iostream>
#include <utility>
#include <stack>
#include <cstring>
using namespace std;

int A[1000000];

int main()
{
	int n;
	cin >> n;
	stack<pair<int, int>> s;
	memset(A, -1, sizeof(A));
	for ( int i = 0; i < n; i++ )
	{
		int number;
		cin >> number;
		while ( !s.empty() && s.top().first < number )
		{
			A[s.top().second] = number;
			s.pop();
		}
		s.push(make_pair(number, i));
	}
	
	for ( int i = 0; i < n; i++ )
	{
		cout << A[i] << ' ';
	}
	return 0;
}