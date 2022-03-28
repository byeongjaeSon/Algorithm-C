#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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
		cout << upper_bound(A.begin(), A.end(), val) - lower_bound(A.begin(), A.end(), val) << ' ';
	}
	return 0;
}