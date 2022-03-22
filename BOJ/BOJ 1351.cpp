//#include <iostream>
//#include <unordered_map>
//using namespace std;
//using ll = long long;
//
//unordered_map<ll, ll> cache;
//ll n, p, q;
//
//ll solve(ll k)
//{
//	if ( k == 0 ) return 1;
//	if ( cache.find(k) != cache.end() ) return cache[k];
//	return cache[k] = solve(k / p) + solve(k / q);
//}
//
//int main()
//{
//	cin >> n >> p >> q;
//	cout << solve(n) << '\n';
//	return 0;
//}