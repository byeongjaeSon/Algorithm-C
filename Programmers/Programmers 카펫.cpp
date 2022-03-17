#include <vector>
using namespace std;

// brown + yellow = m * n 
vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    int numOfblock = brown + yellow;
    for (int m = 1; m * m <= numOfblock; m++)
    {
        if (numOfblock % m == 0) {
            int n = numOfblock / m;
            int edgeBlockCnt = 2 * (m+n) - 4;
            
            if (brown == edgeBlockCnt) {
                answer.push_back(n);
                answer.push_back(m);
                break;
            }
        }
    }
    
    return answer;
}