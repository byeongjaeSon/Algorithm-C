#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[101][101];

void init(int& rows, int& columns)
{
    for ( int i = 1; i <= rows; i++ )
        for ( int j = 1; j <= columns; j++ )
            matrix[i - 1][j - 1] = (i - 1) * columns + j;
}

int rotate(vector<int> query)
{

    pair<int, int> upperLeft = { query[0] - 1, query[1] - 1 };
    pair<int, int> lowerRight = { query[2] - 1, query[3] - 1 };

    int y = upperLeft.first, x = upperLeft.second;
    int tmp = matrix[y][x];
    int ret = tmp;

    for ( ; y < lowerRight.first; y++ )
    {
        matrix[y][x] = matrix[y + 1][x];
        ret = min(ret, matrix[y][x]);
    }

    for ( ; x < lowerRight.second; x++ )
    {
        matrix[y][x] = matrix[y][x + 1];
        ret = min(ret, matrix[y][x]);
    }

    for ( ; y > upperLeft.first; y-- )
    {
        matrix[y][x] = matrix[y - 1][x];
        ret = min(ret, matrix[y][x]);
    }

    for ( ; x > upperLeft.second; x-- )
    {
        matrix[y][x] = matrix[y][x - 1];
        ret = min(ret, matrix[y][x]);
    }

    matrix[y][x + 1] = tmp;

    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{

    init(rows, columns);

    vector<int> answer;
    int queryNum = queries.size();
    for ( int i = 0; i < queryNum; i++ )
    {
        answer.push_back(rotate(queries[i]));
    }

    return answer;
}