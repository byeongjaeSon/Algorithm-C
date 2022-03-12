#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location)
{

    queue<pair<int, int>> q; // {location , priority} 
    unordered_map<int, int> um; // {1~9, cnt}
    int len = priorities.size();
    for ( int i = 0; i < len; i++ )
    {
        q.push(make_pair(i, priorities[i]));
        um[priorities[i]]++;
    }

    int answer = 0;
    while ( 1 )
    {
        pair<int, int> qfront = q.front();
        q.pop();

        bool ishigherPriority = false;
        for ( int priority = qfront.second + 1; priority < 10; priority++ )
        {
            if ( um[priority] > 0 )
            {
                ishigherPriority = true;
                break;
            }
        }

        if ( ishigherPriority )
        {
            q.push(qfront);
        }
        else
        {
            answer++;
            um[qfront.second]--;
            if ( qfront.first == location ) break;
        }
    }

    return answer;
}