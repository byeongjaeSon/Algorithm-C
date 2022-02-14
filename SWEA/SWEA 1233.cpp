#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node_
{
	int left;
	char word;
	int right;
} node[1001];

bool solve(int v)
{
	if ( node[v].left == 0 && node[v].right == 0 )
	{
		if ( ('1' <= node[v].word && node[v].word <= '9') ) return true;
		else return false;
	}

	if ( node[v].left != 0 )
		if ( !solve(node[v].left) ) return false;

	bool flag = false;
	if ( node[v].word == '+' || node[v].word == '-' || node[v].word == '*' || node[v].word == '/' )
		flag = true;

	if ( flag == false ) return false;

	if ( node[v].right != 0 )
		if ( !solve(node[v].right) ) return false;


	return true;
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
		int n;
		cin >> n;

		int addr;
		char str;
		for ( int i = 0; i < n; i++ )
		{
			cin >> addr >> str;
			node[addr].word = str;
			node[addr].left = node[addr].right = 0;
			if ( addr * 2 <= n )
			{
				cin >> node[addr].left;
				if ( addr * 2 + 1 <= n )
					cin >> node[addr].right;
			}
		}

		cout << "#" << tc << " " << solve(1) << '\n';
	}
	return 0;
}