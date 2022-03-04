#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool confirmRules(int n, vector<string>& data, vector<char>& friends)
{

    for ( int i = 0; i < n; i++ )
    {
        string rule = data[i];
        char friend1 = rule[0], friend2 = rule[2];
        char op = rule[3];
        int ruleDist = rule[4] - '0';

        int friend1Pos = 0, friend2Pos = 0;
        for ( int j = 0; j < 8; j++ )
        {
            if ( friend1 == friends[j] ) friend1Pos = j;
            if ( friend2 == friends[j] ) friend2Pos = j;
        }
        int friendDist = abs(friend1Pos - friend2Pos) - 1;

        if ( op == '=' && friendDist != ruleDist ) return false;
        else if ( op == '>' && friendDist <= ruleDist ) return false;
        else if ( op == '<' && friendDist >= ruleDist ) return false;
    }
    return true;
}

int solution(int n, vector<string> data)
{

    vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

    int answer = 0;

    do
    {
        if ( confirmRules(n, data, friends) ) answer++;
    }
    while ( next_permutation(friends.begin(), friends.end()) );

    return answer;
}