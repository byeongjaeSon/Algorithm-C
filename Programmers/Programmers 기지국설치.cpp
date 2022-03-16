#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, lo = 1;
    for ( int& station : stations )
    {
        double width = (station - w) - lo;
        answer += ceil(width / (2 * w + 1));
        lo = station + w + 1;
    }
    answer += ceil(((n + 1) - lo) / (double)(2 * w + 1));

    return answer;
}