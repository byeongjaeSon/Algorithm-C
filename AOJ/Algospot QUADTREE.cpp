#include <iostream>
#include <string>
using namespace std;

string str;
string inverseQuadtree(int &pos)
{
	if ( str[pos] != 'x' ) return string(1, str[pos]);
	string upperLeft = inverseQuadtree(++pos);
	string upperRight = inverseQuadtree(++pos);
	string lowerLeft = inverseQuadtree(++pos);
	string lowerRight = inverseQuadtree(++pos);
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{
		cin >> str;
		int pos = 0;
		cout << inverseQuadtree(pos) << '\n';
	}
	return 0;
}