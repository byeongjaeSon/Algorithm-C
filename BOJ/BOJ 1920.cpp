#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> A(n);
	for ( int i = 0; i < n; i++ )
		cin >> A[i];

	sort(A.begin(), A.end());

	cin >> m;
	for ( int i = 0; i < m; i++ )
	{
		int val;
		cin >> val;
		if ( binary_search(A.begin(), A.end(), val) ) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}