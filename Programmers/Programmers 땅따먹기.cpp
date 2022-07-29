#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int colNum = 4;
int n;

// 1번 방식 : DP
/*
int dp[100000][colNum];

void fillDpTable(vector<vector<int>>& land) {
    for (int col = 0; col < colNum; col++) {
        dp[0][col] = land[0][col];
    }
    
    for (int currRow = 1; currRow < n; currRow++) {
        for (int currCol = 0; currCol < colNum; currCol++) {
            for (int prevCol = 0; prevCol < colNum; prevCol++) {
                if (currCol == prevCol) continue;
                dp[currRow][currCol] = max(dp[currRow][currCol], dp[currRow-1][prevCol]);
            }
            dp[currRow][currCol] += land[currRow][currCol];
        }    
    }    
}

int getMaxDpValue() {
    int ret = -1;
    for (int col = 0; col < colNum; col++) {
        if (dp[n-1][col] > ret) ret = dp[n-1][col];
    }
    return ret;
}
*/

// 2번방식 DP + 슬라이딩 윈도우
int dp2[colNum];

int slidingWindow(vector<vector<int>>& land) {
    for (int col = 0; col < colNum; col++) {
        dp2[col] = land[0][col];
    }
    
    for (int currRow = 1; currRow < n; currRow++) {
        int temp[4] ={dp2[0], dp2[1], dp2[2], dp2[3]};
        dp2[0] = max({temp[1], temp[2], temp[3]}) + land[currRow][0];
        dp2[1] = max({temp[0], temp[2], temp[3]}) + land[currRow][1];
        dp2[2] = max({temp[0], temp[1], temp[3]}) + land[currRow][2];
        dp2[3] = max({temp[0], temp[1], temp[2]}) + land[currRow][3];
    }
    
    return max({dp2[0], dp2[1], dp2[2], dp2[3]});
}

int solution(vector<vector<int> > land)
{
    n = land.size();
    return slidingWindow(land);

    /* 1번 방법
    memset(dp, -1, sizeof(dp));
    fillDpTable(land);
    return getMaxDpValue();
    */
}
