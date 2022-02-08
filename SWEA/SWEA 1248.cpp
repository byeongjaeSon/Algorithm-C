#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<vector<int>> adjList;
int V, E, v1, v2;
int commonAncestor = 0, num = 0;

pair<bool, int> searchTree(int root)
{
	if ( adjList[root].empty() )
		return make_pair((v1 == root || v2 == root), 1);
	else if ( adjList[root].size() == 1 )
	{
		pair<bool, int> ret = searchTree(adjList[root][0]);
		if ( ret.second == -1 ) return make_pair(true, -1);
		return make_pair((ret.first || v1 == root || v2 == root), ret.second + 1);
	}
	else
	{
		pair<bool, int> ret1 = searchTree(adjList[root][0]);
		pair<bool, int> ret2 = searchTree(adjList[root][1]);
		if ( ret1.second == -1 || ret2.second == -1 ) return make_pair(true, -1);

		if ( (ret1.first && ret2.first))
		{
			commonAncestor = root;
			num = ret1.second + ret2.second + 1;
			return make_pair(true, -1);
		}
		else
			return make_pair((ret1.first || ret2.first || v1 == root || v2 == root), ret1.second + ret2.second + 1);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for ( test_case = 1; test_case <= T; ++test_case )
	{
		
		cin >> V >> E >> v1 >> v2;
		adjList = vector<vector<int>>(V+1);
		for ( int i = 0; i < E; i++ )
		{
			int parent, child;
			cin >> parent >> child;
			adjList[parent].push_back(child);
		}

		commonAncestor = 0, num = 0;
		searchTree(1);
		cout << "#" << test_case << " " << commonAncestor << " " << num << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}