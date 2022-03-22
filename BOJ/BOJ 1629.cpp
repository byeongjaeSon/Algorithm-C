#include <iostream>

using namespace std;
using ll = long long; 

ll power_dnc(ll a, ll b, ll c)
{
	if ( b == 0 ) return 1;

	if ( b % 2 == 0 )
	{
		ll half = power_dnc(a, b / 2, c);
		return ((half % c) * (half % c)) % c;
	}
	else return ((a % c) * (power_dnc(a, b - 1, c) % c)) % c;
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;

	cout << power_dnc(a, b, c) << '\n';
	return 0;
}