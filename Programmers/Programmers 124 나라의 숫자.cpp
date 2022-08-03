#include <string>
#include <cmath>

using namespace std;

const string remainMapping = "412";

string solution(int n) {
    
    string answer = "";
    
    const double k = (double)(((n*2)/3)+1);
    const double base = 3.0;
    int level = n <= 3 ? 1 : (log(k)/log(base)) + 1;
    int nth = n <= 3 ? n : n - (pow(3, level-1)-1)*3/2;    
    
    while (level > 0) {
        answer = remainMapping[nth%3] + answer;
        level--;
        nth = ceil(nth/(3.0));
    }
    
    return answer;
}
