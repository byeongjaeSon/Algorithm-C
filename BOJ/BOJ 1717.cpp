#include <iostream>
#include <cstring>

using namespace std;

int parent[1000001];

void makeSet(int n)
{
    for ( int i = 0; i <= n; i++ )
        parent[i] = i;
}

int findSet(int u)
{
    if ( u == parent[u] ) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v)
{
    parent[findSet(u)] = findSet(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    makeSet(n);

    while ( m-- )
    {
        int cmd, u, v;
        cin >> cmd >> u >> v;

        if ( cmd == 0 ) unionSet(u, v);
        else if ( cmd == 1 )
        {
            if ( findSet(u) == findSet(v) ) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }
    return 0;
}