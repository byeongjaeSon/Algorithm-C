#include <iostream>
#include <queue>
using namespace std;

#define RIPEN 1
#define UNRIPEN 0
#define EMPTY -1

class Pos
{
public :
	int x, y, z;

	Pos(int x_, int y_, int z_) : x(x_), y(y_), z(z_) 
	{
	}
};

bool visited[101][101][101];
int tomatoBox[101][101][101];
queue<Pos> q;

int dy[6] = { 0,0,-1,0,1,0 };
int dx[6] = { 0,0,0,1,0,-1 };
int dz[6] = { 1,-1,0,0,0,0 };

bool isTmt(int width, int vertical, int height)
{
	for ( int z = 0; z < height; z++ )
		for ( int y = 0; y < vertical; y++ )
			for ( int x = 0; x < width; x++ )
				if ( tomatoBox[x][y][z] == UNRIPEN || tomatoBox[x][y][z] == RIPEN ) return true;

	return false;
}

int main()
{
	int width, vertical, height, status, unripenCnt = 0;
	cin >> width >> vertical >> height;

	for ( int z = 0; z < height; z++ )
		for ( int y = 0; y < vertical; y++ )
			for ( int x = 0; x < width; x++ )
			{
				cin >> status;
				tomatoBox[x][y][z] = status;
				if ( status == RIPEN )
				{
					visited[x][y][z] = true;
					q.push(Pos(x, y, z));
				}
				else if ( status == UNRIPEN ) unripenCnt++;
			}

	if ( !isTmt(width, vertical, height) )
	{
		cout << -1 << '\n';
		return 0;
	}

	int day = 0;
	while ( !q.empty() )
	{
		if ( unripenCnt == 0 ) break;

		int qSize = q.size();
		for ( int i = 0; i < qSize; i++ )
		{
			Pos pos = q.front();
			q.pop();
			for ( int direction = 0; direction < 6; direction++ )
			{
				int nextX = pos.x + dx[direction];
				int nextY = pos.y + dy[direction];
				int nextZ = pos.z + dz[direction];
				
				// outOfBound È®ÀÎ.
				if ( nextX < 0 || nextX >= width || nextY < 0 || nextY >= vertical || nextZ < 0 || nextZ >= height )
					continue;

				if ( !visited[nextX][nextY][nextZ] && tomatoBox[nextX][nextY][nextZ] == UNRIPEN )
				{
					visited[nextX][nextY][nextZ] = true;
					q.push(Pos(nextX, nextY, nextZ));
					tomatoBox[nextX][nextY][nextZ] = RIPEN;
					unripenCnt--;
				}	
			}
		}
		day++;
	}

	if ( unripenCnt != 0 ) day = -1;
	cout << day << '\n';

	return 0;
}