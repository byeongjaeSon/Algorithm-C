#include <iostream>
using namespace std;

int A[100001];
int pSum[100001];
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ )
		cin >> A[i];

	pSum[1] = A[1];
	for ( int i = 2; i <= n; i++ )
		pSum[i] = pSum[i - 1] + A[i];

	for ( int c = 0; c < m; c++ )
	{
		int i, j;
		cin >> i >> j;
		if ( i == 1 ) cout << pSum[j] << '\n';
		else cout << pSum[j] - pSum[i - 1] << '\n';
	}

	return 0;
}