#include <iostream>
using namespace std;

bool canAnswer[1000];
int n;

bool isPossible(int question, int num, int numOfStrkie, int numOfBall)
{
	int q[3], compare[3], div = 100;
	for ( int i = 2; i >= 0; i-- )
	{
		q[i] = question / div;
		compare[i] = num / div;
		question %= div;
		num %= div;
		div /= 10;
	}

	int s = 0, b = 0;
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			if ( q[i] == compare[j] )
			{
				if ( i == j ) s++;
				else b++;
			}
		}
	}
	if ( numOfStrkie == s && numOfBall == b ) return true;
	else return false;
}


void eraseAnswer(int cnt)
{
	if ( cnt == n ) return;

	int question, numOfStrkie, numOfBall;
	cin >> question >> numOfStrkie >> numOfBall;


	if ( cnt == 0 )
	{
		for ( int i = 1; i < 10; i++ )
		{
			for ( int j = 1; j < 10; j++ )
			{
				if ( i == j ) continue;
				for ( int k = 1; k < 10; k++ )
				{
					if ( i == k || j == k ) continue;
					int num = i * 100 + j * 10 + k;
					if ( isPossible(question, num, numOfStrkie, numOfBall) ) canAnswer[num] = true;
				}
			}
		}

	}
	else
	{
		for ( int i = 1; i < 10; i++ )
		{
			for ( int j = 1; j < 10; j++ )
			{
				if ( i == j ) continue;
				for ( int k = 1; k < 10; k++ )
				{
					if ( i == k || j == k ) continue;
					int num = i * 100 + j * 10 + k;

					if ( canAnswer[num] && !isPossible(question, num, numOfStrkie, numOfBall) )
						canAnswer[num] = false;

				}
			}
		}
	}
	eraseAnswer(cnt + 1);
}

int main()
{
	int ret = 0;
	cin >> n;
	eraseAnswer(0);
	for ( int num = 100; num < 1000; num++ )
		if ( canAnswer[num] ) ret++;
	cout << ret << '\n';
	return 0;
}