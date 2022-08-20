#include <string>
#include <vector>
 
#define INF 987654321
using namespace std;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Make_Distance(vector<vector<int>> fares, vector<vector<int>> &Dist, int n)
{
    for (int i = 0; i < fares.size(); i++)
    {
        int S = fares[i][0];
        int E = fares[i][1];
        int D = fares[i][2];
        Dist[S][E] = D;
        Dist[E][S] = D;
    }
    for (int i = 1; i <= n; i++) Dist[i][i] = 0;
}
 
void Floyd_Warshall(int n, vector<vector<int>> &Dist)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || i == k || k == j) continue;
                if(Dist[i][k] != INF && Dist[k][j] != INF) Dist[i][j] = Min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }
}
 
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 0;
    vector<vector<int>> Dist(n + 1, vector<int>(n + 1, INF));
    Make_Distance(fares, Dist, n);
    Floyd_Warshall(n, Dist);
 
    answer = Dist[s][a] + Dist[s][b];
    for (int i = 1; i <= n; i++)
    {
        if (Dist[s][i] != INF && Dist[i][a] != INF && Dist[i][b] != INF)
        {
            answer = Min(answer, Dist[s][i] + Dist[i][a] + Dist[i][b]);
        }
    }
    return answer;
}
