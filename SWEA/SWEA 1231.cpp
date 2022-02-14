#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct _Node
{
	char word;
	int left;
	int right;
} node[101];

int N, addr;
char str;


void solve(int v)
{
	if ( node[v].left > 0 )
		solve(node[v].left);
	cout << node[v].word;
	if ( node[v].right > 0 )
		solve(node[v].right);
}

void input()
{
	int i;
	for ( int i = 0; i < N; i++ )
	{
		cin >> addr >> str;

		node[addr].word = str;
		node[addr].left = node[addr].right = 0;

		if ( addr * 2 <= N )
		{
			cin >> node[addr].left;
			if ( addr * 2 + 1 <= N )
				cin >> node[addr].right;
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int t = 10;
	for ( int tc = 1; tc <= t; ++tc )
	{
		cin >> N;
		input();
		cout << "#" << tc << " ";
		solve(1);
		cout << '\n';
	}
	return 0;
}