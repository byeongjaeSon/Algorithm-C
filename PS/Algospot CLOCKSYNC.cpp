#include <iostream>
using namespace std;
#define INF 987654321

int clocks[16];
bool isConnected[10][16] =
{
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool AllTwelve()
{
	for ( int i = 0; i < 16; i++ )
		if ( clocks[i] != 12 ) return false;
	return true;
}

void turnClocks(int numOfswitch, int n, int direct)
{
	for ( int i = 0; i < 16; i++ )
	{
		if ( isConnected[numOfswitch][i] )
		{
			clocks[i] = (clocks[i] + (direct * 3 * n)) % 12;
			if ( clocks[i] <= 0 ) clocks[i] += 12;
		}		
	}
}

int makeTwelve(int numOfswitch, int cnt)
{
	
	if ( AllTwelve() ) return cnt;
	if ( numOfswitch == 10 ) return INF;
	int ret = INF;

	for ( int i = 0; i < 4; i++ )
	{


		turnClocks(numOfswitch, i, 1);
		int candi = makeTwelve(numOfswitch + 1, cnt + i);
		ret = min(ret, candi);
		turnClocks(numOfswitch, i, -1);
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;
	for ( int i = 0; i < c; i++ )
	{
		for ( int i = 0; i < 16; i++ )
			cin >> clocks[i];

		int answer = makeTwelve(0, 0);
		if ( answer == INF ) answer = -1;
		cout << answer << endl;
	}
	return 0;
}