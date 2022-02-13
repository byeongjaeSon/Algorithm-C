int graph[100][100];
int cnts[100];
const int STACK_SIZE = 1000;
int stack[STACK_SIZE];

void dfs_init(int N, int path[100][2])
{
	for ( int i = 0; i < 100; ++i )
		for ( int j = 0; j < 100; ++j )
			graph[i][j] = 0;

	for ( int i = 0; i < 100; ++i )
		cnts[i] = 0;

	for ( int i = 0; i < N - 1; ++i )
	{
		int parent = path[i][0];
		int child = path[i][1];
		graph[parent][cnts[parent]++] = child;
	}
}

int dfs(int n)
{
	bool visited[100] = { false };
	int top = -1;

	stack[++top] = n;
	int ret = n;
	while ( top != -1 )
	{
		int curr = stack[top--];
		if ( !visited[curr] )
		{
			visited[curr] = true;

			if ( curr > ret ) return curr;

			for ( int i = cnts[curr] - 1; i >= 0; --i )
			{
				if ( !visited[graph[curr][i]] )
					stack[++top] = graph[curr][i];
			}
		}
	}

	return -1;
}
