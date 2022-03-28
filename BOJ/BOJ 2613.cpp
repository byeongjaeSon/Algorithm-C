#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numbers[301];
int prefixSum[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
	{
		cin >> numbers[i];
		if ( i == 0 ) prefixSum[i] = numbers[i];
		else prefixSum[i] = prefixSum[i - 1] + numbers[i];
	}

	int ret = 987654321;
	int retArr[3];
	// [0..i] [i+1 .. j] [j+1 .. n-1]
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			if ( (j - i == 0) || ((n - 1 - j) == 0) ) continue;


			int sum1 = prefixSum[i];
			int sum2 = prefixSum[j] - prefixSum[i];
			int sum3 = prefixSum[n - 1] - prefixSum[j];
			int tempSum = max({ sum1, sum2, sum3 });
			
			if ( tempSum < ret )
			{
				ret = tempSum;
				retArr[0] = i + 1;
				retArr[1] = j - i;
				retArr[2] = (n - 1) - j;
			}
		}
	}

	cout << ret << '\n';
	for ( int& e : retArr )
		cout << e << " ";

	return 0;
}