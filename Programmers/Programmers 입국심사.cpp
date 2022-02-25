#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long lo = 1;
    long long hi = (*min_element(times.begin(), times.end())) * (long long)n + 1;

    // lo < hi
    // [lo, hi) 사이에 찾고자 하는 값이 존재한다.
    while ( lo < hi )
    {
        long long mid = (lo + hi) / 2;

        long long sum = 0;
        for ( int& time : times )
            sum += mid / (long long)time;

        if ( sum > n ) hi = mid;
        else if ( sum < n ) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}