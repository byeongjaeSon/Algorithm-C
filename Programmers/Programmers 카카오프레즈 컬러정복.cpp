#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
bool visited[101][101];
int number_of_area;
int max_size_of_one_area;


pair<int, int> getAreaStartingPoint(int m, int n, vector<vector<int>>& picture)
{
    for ( int y = 0; y < m; y++ )
    {
        for ( int x = 0; x < n; x++ )
        {
            if ( picture[y][x] != 0 && !visited[y][x] )
                return make_pair(y, x);
        }
    }

    return make_pair(-1, -1);
}

void bfs(int m, int n, vector<vector<int>>& picture)
{
    queue<pair<int, int>> q;
    while ( 1 )
    {
        pair<int, int> start = getAreaStartingPoint(m, n, picture);
        if ( start.first == -1 ) break;
        visited[start.first][start.second] = true;
        q.push(start);
        number_of_area++;
        int areaSize = 0;
        while ( !q.empty() )
        {
            pair<int, int> curr = q.front();
            q.pop();
            areaSize++;
            for ( int direction = 0; direction < 4; direction++ )
            {
                int nextY = curr.first + dy[direction];
                int nextX = curr.second + dx[direction];

                if ( nextY < 0 || nextY >= m || nextX < 0 || nextX >= n ) continue;
                if ( picture[nextY][nextX] != picture[start.first][start.second] ) continue;

                if ( !visited[nextY][nextX] )
                {
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY, nextX));
                }

            }
        }
        max_size_of_one_area = max(areaSize, max_size_of_one_area);
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    memset(visited, false, sizeof(visited));
    number_of_area = max_size_of_one_area = 0;

    bfs(m, n, picture);

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}