#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

double cache[101][50];
int adjCnt[50];
int adjMtx[50][50];
int n, d, p, t, q;

void predict(int day)
{
	if ( day == d+1 ) return;

	for ( int from = 0; from < n; from++ )
	{
		for ( int to = 0; to < n; to++ )
		{
			if ( cache[day - 1][from] > 0 && adjMtx[from][to] == 1 )
				cache[day][to] += (1.0 / adjCnt[from]) * cache[day - 1][from];
		}
	}

	predict(day + 1);
}


int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{	
		memset(cache, 0, sizeof(cache));
		memset(adjCnt, 0, sizeof(adjCnt));
		memset(adjMtx, 0, sizeof(adjMtx));

		cin >> n >> d >> p;
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
			{
				cin >> adjMtx[i][j];
				if ( adjMtx[i][j] == 1 ) adjCnt[i]++;
			}


		for ( int i = 0; i < n; i++ )
		{
			if ( adjMtx[p][i] == 1 )
				cache[1][i] += adjCnt[p] != 0 ? (1.0 / adjCnt[p]) : 0;
		}

		predict(2);

		cin >> t;
		cout << fixed;
		cout.precision(8);
		for ( int i = 0; i < t; i++ )
		{
			cin >> q;
			cout << cache[d][q] << ' ';
		}
		cout << '\n';
	}
	return 0;
}