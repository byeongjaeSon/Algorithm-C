#include <string>
using namespace std;

int solution(string s)
{
    int len = s.length(), result = len;
    for (int sliceWidth = 1; sliceWidth <= len/2; sliceWidth++) {
        string compressed = "";
        int dupCnt = 1, pos = sliceWidth;
        string cmpWord = s.substr(0, sliceWidth);
        
        while (pos < len) {
            if (cmpWord == s.substr(pos, sliceWidth)) {
                dupCnt++;
                pos += sliceWidth;
                continue;
            }
            
            if (dupCnt != 1) compressed += to_string(dupCnt);
            compressed += cmpWord;
            
            dupCnt = 1;
            cmpWord = s.substr(pos, sliceWidth);
            pos += sliceWidth;
        }
        if (dupCnt != 1) compressed += to_string(dupCnt);
        compressed += cmpWord;
        
        if (result > compressed.length()) result = compressed.length();
    }
    return result;
}
