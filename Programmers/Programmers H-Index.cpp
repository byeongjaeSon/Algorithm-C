#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    int answer = 0;
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int h = citations[n-1]; h >= 0; h--) {
        int up = n - (lower_bound(citations.begin(), citations.end(), h) - citations.begin());
        int down = upper_bound(citations.begin(), citations.end(), h) - citations.begin();        
        if (up >= h && down <= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}
