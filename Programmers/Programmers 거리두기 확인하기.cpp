#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

char room[5][5];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool isFar(vector<string>& place)
{
    queue<pair<int, int>> waitPos;

    for ( int i = 0; i < 5; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            room[i][j] = place[i][j];
            if ( room[i][j] == 'P' ) waitPos.push(make_pair(i, j));
        }
    }

    while ( !waitPos.empty() )
    {

        bool visited[5][5] = { false, };

        pair<int, int> startPos = waitPos.front();
        waitPos.pop();
        visited[startPos.first][startPos.second] = true;

        queue<pair<int, int>> q;
        q.push(startPos);

        int dist = 0;
        while ( dist <= 2 )
        {

            int qSize = q.size();
            for ( int i = 0; i < qSize; i++ )
            {
                pair<int, int> curr = q.front();
                q.pop();

                if ( room[curr.first][curr.second] == 'P' &&
                    (curr.first != startPos.first || curr.second != startPos.second) )
                    return false;

                for ( int direction = 0; direction < 4; direction++ )
                {
                    int nextY = curr.first + dy[direction];
                    int nextX = curr.second + dx[direction];

                    if ( nextY < 0 || nextY >= 5 || nextX < 0 || nextX >= 5 ) continue;
                    if ( room[nextY][nextX] == 'X' ) continue;

                    if ( !visited[nextY][nextX] )
                    {
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
            dist++;
        }
        q = {};
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for ( int i = 0; i < places.size(); i++ )
    {
        if ( isFar(places[i]) ) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}