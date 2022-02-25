#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{

    int size = progresses.size();
    vector<int> waitDays(size, 0);
    for ( int i = 0; i < size; i++ )
        waitDays[i] = ceil((100.0 - progresses[i]) / speeds[i]);

    vector<int> answer;
    int start = 0;
    while ( start != size )
    {
        int end = start + 1;
        for ( ; end <= size; end++ )
        {
            if ( end == size ) break;
            if ( waitDays[end] > waitDays[start] ) break;
        }

        answer.push_back(end - start);
        start = end;
    }

    return answer;
}