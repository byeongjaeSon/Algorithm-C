#define MAX_NODE 10000

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data)
{
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
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
	newNode->prev = head;
	if ( head->next != nullptr ) head->next->prev = newNode;
	head->next = newNode;
}

void addNode2Tail(int data)
{
	Node* newNode = getNode(data);
	Node* pNode = head;
	
	while ( pNode->next != nullptr )
		pNode = pNode->next;

	newNode->prev = pNode;
	pNode->next = newNode;
}

void addNode2Num(int data, int num)
{
	Node* newNode = getNode(data);
	Node* pNode = head;

	for ( int i = 0; i < num-1; i++ )
		pNode = pNode->next;

	newNode->prev = pNode;
	newNode->next = pNode->next;
	if ( pNode->next != nullptr ) pNode->next->prev = newNode;
	pNode->next = newNode;
	
}

int findNode(int data)
{
	int num = 0;

	Node* pNode = head;
	while ( pNode != nullptr && pNode->data != data )
	{
		pNode = pNode->next;
		++num;
	}

	return num;
}

void removeNode(int data)
{
	Node* pNode = head;
	while ( pNode != nullptr && pNode->data != data )
		pNode = pNode->next;
	
	if ( pNode != nullptr )
	{
		pNode->prev->next = pNode->next;
		if ( pNode->next != nullptr) pNode->next->prev = pNode->prev;
	}
}

int getList(int output[MAX_NODE])
{
	int cnt = 0;
	Node* pNode = head->next;
	while ( pNode != nullptr )
	{
		output[cnt++] = pNode->data;
		pNode = pNode->next;
	}
		
	return cnt;
}

int getReversedList(int output[MAX_NODE])
{
	Node* pNode = head;
	while ( pNode->next != nullptr )
		pNode = pNode->next;
	
	int cnt = 0;
	while ( pNode != head )
	{
		output[cnt++] = pNode->data;
		pNode = pNode->prev;
	}

	return cnt;

}