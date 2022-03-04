#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int cache[101][101];
bool isPuddle[101][101];

int solve(int y, int x)
{
    if ( y < 0 || x < 0 || isPuddle[y][x] ) return 0;
    if ( y == 0 && x == 0 ) return 1;

    int& ret = cache[y][x];
    if ( ret != -1 ) return ret;

    return ret = (solve(y - 1, x) % MOD + solve(y, x - 1) % MOD) % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles)
{

    memset(cache, -1, sizeof(cache));
    memset(isPuddle, false, sizeof(isPuddle));

    for ( int i = 0; i < puddles.size(); i++ )
        isPuddle[puddles[i][0] - 1][puddles[i][1] - 1] = true;


    int answer = solve(m - 1, n - 1);
    return answer;
}