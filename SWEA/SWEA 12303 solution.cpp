#define MAX_NODE 10000

struct Node
{
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data)
{
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);
	newNode->next = head->next;
	head->next = newNode;
}

void addNode2Tail(int data)
{
	Node* newNode = getNode(data);

	Node* pNode = head;
	while ( pNode->next != nullptr )
		pNode = pNode->next;

	pNode->next = newNode;
}

void addNode2Num(int data, int num)
{
	Node* newNode = getNode(data);
	Node* pNode = head;
	for ( int i = 0; i < num-1; i++ )
		pNode = pNode->next;

	newNode->next = pNode->next;
	pNode->next = newNode;
}

void removeNode(int data)
{
	Node* pNode = head;
	while ( pNode->next != nullptr && pNode->next->data != data )
		pNode = pNode->next;

	if ( pNode->next != nullptr )
		pNode->next = pNode->next->next;
}

int getList(int output[MAX_NODE])
{
	Node* pNode = head->next;
	int cnt = 0;
	while ( pNode != nullptr )
	{
		output[cnt++] = pNode->data;
		pNode = pNode->next;
	}
	return cnt;
		
}