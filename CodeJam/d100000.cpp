#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for ( int tc = 1; tc <= t; tc++ )
    {
        int n;
        cin >> n;
        vector<int> dices(n);
        for ( int i = 0; i < n; i++ )
            cin >> dices[i];

        sort(dices.begin(), dices.end());

        int num = 1;
        for ( int i = 0; i < n; i++ )
            if ( dices[i] >= num ) num++;

        cout << "Case #" << tc << ": " << num << '\n';
    }
    return 0;
}