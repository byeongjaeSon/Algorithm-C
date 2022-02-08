#include <iostream>
#include <vector>
using namespace std;

struct INFO
{
	int t;
	long long a;
	long long h;
};

int N;
long long HATK, maxVal;
vector<INFO> room;

bool clearDungeon(long long maxHP, long long atk)
{
	long long currHP = maxHP;
	for ( int i = 0; i < N; i++ )
	{
		if ( room[i].t == 1 )
		{
			int atkCnt;
			if ( room[i].h % atk == 0 ) atkCnt = room[i].h / atk;
			else atkCnt = room[i].h / atk + 1;
			int hitCnt = atkCnt - 1;
			currHP -= room[i].a * hitCnt;
			if ( currHP <= 0 ) return false;
		}
		else if ( room[i].t == 2 )
		{
			atk += room[i].a;
			currHP += room[i].h;
			if ( currHP > maxHP ) currHP = maxHP;
		}
	}
	return true;
}

int main()
{
	cin >> N >> HATK;
	room.resize(N);
	for ( int i = 0; i < N; i++ )
	{
		cin >> room[i].t >> room[i].a >> room[i].h;
		if ( room[i].t == 1 ) maxVal += room[i].a * room[i].h;
	}

	long long lo = 0, hi = maxVal;
	while ( lo + 1 < hi )
	{
		long long mid = (lo + hi) / 2;
		if ( clearDungeon(mid, HATK) ) hi = mid;
		else lo = mid;
	}
	cout << hi << '\n';
	return 0;
}