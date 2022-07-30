#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 1000
int triangle[MAX_N][MAX_N];
int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};

void fillTriangle(int& n) {
    
    memset(triangle, -1, sizeof(triangle));
    
    int currY = 0, currX = 0, number = 1, direction = 0;
    while (1) {
        triangle[currY][currX] = number++;
        
        int nextY = currY + dy[direction];
        int nextX = currX + dx[direction];
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || triangle[nextY][nextX] != -1) {
            direction = (direction + 1) % 3;
            nextY = currY + dy[direction];
            nextX = currX + dx[direction];
        }
        
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || triangle[nextY][nextX] != -1) {
            break;
        }
        
        currY = nextY, currX = nextX;
    }
}

vector<int> solution(int n) {

    vector<int> answer;
    fillTriangle(n);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x <= y; x++) {
            answer.push_back(triangle[y][x]);
        }
    }
    
    return answer;
}
