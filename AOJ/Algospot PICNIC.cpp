#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool isFriend[10][10];

bool allPaired(vector<int>& remainedPeople)
{
	for ( int i = 0; i < remainedPeople.size(); i++ )
		if ( remainedPeople[i] != -1 ) return false;
	return true;
}

int makePair(vector<int>& remainedPeople, vector<int>::iterator start)
{
	if ( allPaired(remainedPeople) ) return 1;
	int cnt = 0;

	for ( auto iter1 = start+1; iter1 != remainedPeople.end(); iter1++ )
	{
		int person1 = *iter1;
		for ( auto iter2 = iter1+1; iter2 != remainedPeople.end(); iter2++ )
		{
			int person2 = *iter2;
			if ( person1 == -1 || person2 == -1 ) continue;
			if ( isFriend[person1][person2] )
			{
				*iter1 = *iter2 = -1;
				cnt += makePair(remainedPeople,iter1);
				*iter1 = person1;
				*iter2 = person2;
			}
		}
	}
	return cnt;
}

int main()
{
	int c;
	cin >> c;
	while ( c-- )
	{
		int n, m;
		cin >> n >> m;

		vector<int> remainedPeople(n);
		for ( int i = 0; i < n; i++ )
			remainedPeople[i] = i;

		for ( int i = 0; i < m; i++ )
		{
			int u, v;
			cin >> u >> v;
			isFriend[u][v] = true;
			isFriend[v][u] = true;
		}
		cout << makePair(remainedPeople,remainedPeople.begin()) << '\n';
		memset(isFriend, false, sizeof(isFriend));;
	}
	return 0;
}