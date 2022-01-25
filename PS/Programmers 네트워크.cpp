#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int k, int& n, vector<vector<int>>& computers)
{
    visited[k] = true;
    for ( int i = 0; i < n; i++ )
        if ( !visited[i] && computers[k][i] )
            dfs(i, n, computers);
}

int dfsAll(int n, vector<vector<int>>& computers)
{

    int cnt = 0;
    for ( int i = 0; i < n; i++ )
        if ( !visited[i] )
        {
            cnt++;
            dfs(i, n, computers);
        }
    return cnt;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = dfsAll(n, computers);
    return answer;
}