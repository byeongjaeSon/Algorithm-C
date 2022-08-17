#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    
    int height = triangle.size();
    dp[0][0] = triangle[0][0];
    
    for (int h = 1; h < height; h++) {
       for (int w = 0; w <= h; w++) {
           if (w-1 >= 0) dp[h][w] = max(dp[h][w], dp[h-1][w-1]);
           dp[h][w] = max(dp[h][w], dp[h-1][w]);
           dp[h][w] += triangle[h][w];
       } 
    }
    
    return *max_element(dp[height-1], dp[height-1]+height);
}
