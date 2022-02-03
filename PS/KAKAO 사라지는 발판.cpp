#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
const int INF = 987654321;
int r, c;
int minTurn = INF;
int winner, loser;

class Pos
{
public:
    int y;
    int x;

    Pos(int y_, int x_)
    {
        y = y_;
        x = x_;
    }
};


int play(vector<vector<int>>& board, Pos posA, Pos posB, int turn)
{
    if ( turn % 2 == winner )
    {
        if ( board[posA.y][posA.x] == 0 ) return 0;

        int ret = INF;
        for ( int direction = 0; direction < 4; direction++ )
        {
            int nextY = posA.y + dy[direction];
            int nextX = posA.x + dx[direction];
            if ( 0 <= nextY && nextY < r && 0 <= nextX && nextX < c && board[nextY][nextX] != 0 )
            {
                board[posA.y][posA.x] = 0;
                ret = min(ret, 1 + play(board, Pos(nextY, nextX), posB, turn + 1));
                board[posA.y][posA.x] = 1;
            }
        }
        return ret == INF ? 0 : ret;
    }
    else
    {
        if ( board[posB.y][posB.x] == 0 ) return 0;

        int ret = -1;
        for ( int direction = 0; direction < 4; direction++ )
        {
            int nextY = posB.y + dy[direction];
            int nextX = posB.x + dx[direction];
            if ( 0 <= nextY && nextY < r && 0 <= nextX && nextX < c && board[nextY][nextX] != 0 )
            {
                board[posB.y][posB.x] = 0;
                ret = max(ret, 1 + play(board, posA, Pos(nextY, nextX), turn + 1));
                board[posB.y][posB.x] = 1;
            }
        }
        return ret == -1 ? 0 : ret;
    }
}

void dfs(vector<vector<int>>& board, Pos posA, Pos posB, int turn)
{
    if ( turn % 2 == 0 )
    {
        if ( board[posA.y][posA.x] == 0 && turn < minTurn )
        {
            minTurn = turn;
            winner = 1;
            loser = 0;
            return;
        }

        for ( int direction = 0; direction < 4; direction++ )
        {
            int nextY = posA.y + dy[direction];
            int nextX = posA.x + dx[direction];
            if ( 0 <= nextY && nextY < r && 0 <= nextX && nextX < c && board[nextY][nextX] != 0 )
            {
                board[posA.y][posA.x] = 0;
                dfs(board, Pos(nextY, nextX), posB, turn + 1);
                board[posA.y][posA.x] = 1;
            }
        }
    }
    else
    {
        if ( board[posB.y][posB.x] == 0 && turn < minTurn )
        {
            minTurn = turn;
            winner = 0;
            loser = 1;
            return;
        }

        for ( int direction = 0; direction < 4; direction++ )
        {
            int nextY = posB.y + dy[direction];
            int nextX = posB.x + dx[direction];
            if ( 0 <= nextY && nextY < r && 0 <= nextX && nextX < c && board[nextY][nextX] != 0 )
            {
                board[posB.y][posB.x] = 0;
                dfs(board, posA, Pos(nextY, nextX), turn + 1);
                board[posB.y][posB.x] = 1;
            }
        }
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    r = board.size();
    c = board[0].size();
    Pos posA(aloc[0], aloc[1]);
    Pos posB(bloc[0], bloc[1]);

    dfs(board, posA, posB, 0);
    int answer = play(board, posA, posB, 0);
    return answer;
}