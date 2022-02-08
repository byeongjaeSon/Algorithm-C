#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	const int N = preorder.size();
	if ( preorder.empty() ) return;

	const int root = preorder[0];

	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin(); // 왼쪽 서브트리의 크기
	const int R = N - 1 - L; // 오른쪽 서브트리의 크기

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));

	cout << root << ' ';
}

int main()
{
	int C, n;
	cin >> C;
	while ( C-- )
	{
		cin >> n;
		vector<int>preorder(n);
		vector<int>inorder(n);
		for ( int i = 0; i < n; i++ )
			cin >> preorder[i];
		for ( int i = 0; i < n; i++ )
			cin >> inorder[i];


		printPostOrder(preorder, inorder);
	}
	return 0;
}