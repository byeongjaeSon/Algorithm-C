#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
	int num;
	struct node* left;
	struct node* right;
} Node;

vector<int> inorder;
vector<int> postorder;

typedef vector<int>::iterator vit;

Node* makeTree(vector<int>& inOrder, vector<int>& postOrder)
{
	if ( inOrder.empty() || postOrder.empty() ) return NULL;

	Node* root = new Node;
	int key = *(postOrder.end()-1);
	root->num = key;
	root->left = NULL;
	root->right = NULL;

	auto iter = find(inOrder.begin(), inOrder.end(), key);
	vector<int> leftInOrderSubTree = vector<int>(inOrder.begin(), iter);
	vector<int> leftPostORderSubTree = vector<int>(postOrder.begin(), postOrder.begin() + leftInOrderSubTree.size());
	root->left = makeTree(leftInOrderSubTree, leftPostORderSubTree);

	vector<int> rightInOrderSubTree = vector<int>(++iter, inOrder.end());
	vector<int> rightPostOrderSubTree = vector<int>(postOrder.begin() + leftInOrderSubTree.size(), postOrder.begin() + leftInOrderSubTree.size()+ rightInOrderSubTree.size());
	root->right = makeTree(rightInOrderSubTree, rightPostOrderSubTree);

	return root;
}



Node* makeTree2(vit inOrderHead, vit inOrderTail, vit postOrderHead, vit postOrderTail)
{
	if ( (inOrderHead == inOrderTail) || (postOrderHead == postOrderTail) ) return NULL;
	
	Node* root = new Node;
	int key = *(postOrderTail - 1);
	root->num = key;
	root->left = NULL;
	root->right = NULL;

	vit iter = find(inOrderHead, inOrderTail, key);
	
	int dist = std::distance(inOrderHead, iter); // iter - postOrderHead;
	root->left = makeTree2(inOrderHead, iter, postOrderHead, postOrderHead + dist);
	root->right = makeTree2(++iter, inOrderTail, postOrderHead + dist, postOrderTail - 1);

	return root;
}

void preOrderSearch(Node* root)
{
	if ( root == NULL ) return;

	cout << root->num << ' ';
	preOrderSearch(root->left);
	preOrderSearch(root->right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;

	for ( int i = 0; i < n; i++ )
	{
		cin >> num;
		inorder.push_back(num);
	}
		
	for ( int i = 0; i < n; i++ )
	{
		cin >> num;
		postorder.push_back(num);
	}

	int key = *(postorder.end() - 1);
	
	vit inOrderHead = inorder.begin();
	vit inOrderTail = inorder.end();
	vit postOrderHead = postorder.begin();
	vit postOrderTail = postorder.end();
	
	//Node* root = makeTree(inorder, postorder);
	Node* root = makeTree2(inOrderHead, inOrderTail, postOrderHead, postOrderTail);	

	preOrderSearch(root);
	return 0;
}