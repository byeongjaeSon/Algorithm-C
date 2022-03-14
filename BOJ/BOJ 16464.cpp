#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while ( n-- )
	{
		int k;
		cin >> k;

		if ( k & (k - 1) ) cout << "Gazua" << "\n";
		else cout << "GoHanGang" << '\n';
	}
	return 0;
}