#include <iostream>
#include <string>

using namespace std;

string compressed;

string reverse(int& pos)
{
	if ( compressed[pos++] != 'x' )
		return string(1, compressed[pos-1]);

	string lu = reverse(pos);
	string ru = reverse(pos);
	string ld = reverse(pos);
	string rd = reverse(pos);

	return ("x" + ld + rd + lu + ru);
}

int main()
{
	int tc;
	cin >> tc;
	while ( tc-- )
	{
		cin >> compressed;
		int pos = 0;
		cout << reverse(pos) << '\n';
	}
}