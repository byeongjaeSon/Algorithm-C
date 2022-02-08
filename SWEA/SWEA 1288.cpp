#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		int n;
		cin >> n;
		int pivot = 0x03FF;
		int cnt = 0, num = 0;
		while ( pivot != num )
		{
			cnt++;
			int temp = cnt * n;
			while ( temp )
			{
				num = num | (1 << (temp % 10));
				temp /= 10;
			}
		}
		cout << "#" << test_case << " " << cnt * n << '\n';
	}
	return 0;
}