#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		int n, m;
		int mask = 0;

		cin >> n >> m;
		
		mask = (1 << n) - 1;
		
		if ( (m & mask) == mask ) cout << "#" << test_case << " ON" << '\n';
		else cout << "#" << test_case  << " OFF" << '\n';
	}
	return 0;
}