
typedef struct
{
    int y;
    int x;
} Pos;

const int QUEUE_SIZE = 1000;
int front = -1, rear = -1, Size = 0;
Pos q[QUEUE_SIZE];

int n;
int map_[10][10];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void enqueue(Pos pos)
{
    ++Size;
    rear = (rear + 1) % QUEUE_SIZE;
    q[rear] = pos;
}

Pos dequeue()
{
    --Size;
    front = (front+1) % QUEUE_SIZE;
    return q[front];
}

void bfs_init(int map_size, int map[10][10])
{
    n = map_size;

    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            map_[i][j] = map[i][j];

}
int bfs(int x1, int y1, int x2, int y2)
{
    bool visited[10][10] = { false };
    front = -1, rear = -1, Size = 0;

    Pos pos = { y1-1, x1-1 };
    visited[y1-1][x1-1] = true;
    enqueue(pos);

    int cnt = 0;
    while ( Size != 0 )
    {
        int qSize = Size;
        for ( int i = 0; i < qSize; i++ )
        {
            Pos curr = dequeue();

            if ( curr.y == y2-1 && curr.x == x2-1 ) return cnt;

            for ( int direction = 0; direction < 4; ++direction )
            {
                int nextY = curr.y + dy[direction];
                int nextX = curr.x + dx[direction];

                if ( nextX < 0 || nextX >= n || nextY < 0 || nextY >= n ) continue;
             
                if ( !visited[nextY][nextX] && map_[nextY][nextX] == 0 )
                {
                    visited[nextY][nextX] = true;
                    Pos next = { nextY, nextX };
                    enqueue(next);
                }
            }
        }
        ++cnt;
    }

    return -1;
}