#include <iostream>
#include <vector>
using namespace std;
#define MOD 20091101

int main()
{
	int t;
	cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		int n, k;
		cin >> n >> k;
		vector<int> doll_box(n), psum(n+1), check(k,0);
		for ( int j = 0; j < n; j++ )
		{
			int num;
			cin >> num;
			doll_box[j] = num % k;
		}


		psum[0] = doll_box[0];
		check[psum[0]]++;
		for ( int j = 1; j < n; j++ )
		{
			int temp = (psum[j - 1] + doll_box[j]) % k;
			check[temp]++;
			psum[j] = temp;
		}
		int answer1 = 0, answer2 = 0;;

		answer1 += check[0];
		for ( int j = 1; j < k; j++ )
		{
			if ( check[j] >= 2 )
				answer1 = (answer1 + (check[j] * (check[j] - 1) / 2)) % MOD;
		}	

		vector<int> ret(n, 0);
		vector<int> prev(k, -1);

		for ( int i = 0; i < n; i++ )
		{
			if ( i > 0 )
				ret[i] = ret[i - 1];
			else
				ret[i] = 0;

			int loc = prev[psum[i]];
			if ( loc != -1 ) ret[i] = max(ret[i], ret[loc] + 1);

			prev[psum[i]] = i;
		}
		answer2 = ret.back();

		cout << answer1 << ' ' << answer2 << '\n';
	}
	return 0;
}