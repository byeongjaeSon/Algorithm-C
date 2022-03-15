#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    unordered_map<int, int> um;
    int len = s.length();
    string tmp = "";
    for ( int i = 0; i < len; i++ )
    {
        if ( s[i] == '{' || s[i] == '}' ) continue;
        else if ( '0' <= s[i] && s[i] <= '9' ) tmp += s[i];
        else if ( s[i] == ',' )
        {
            um[stoi(tmp)]++;
            tmp = "";
        }
    }
    um[stoi(tmp)]++;

    vector<pair<int, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), cmp);

    vector<int> answer;

    for ( pair<int, int>& p : v )
        answer.push_back(p.first);

    return answer;
}