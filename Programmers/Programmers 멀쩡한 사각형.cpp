using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    for (int x=1; x <= w-1; x++) {
        answer += (int)((double)h*x/w);
    }
    return answer*2;
}
