#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> checked;

bool isPrime(int number)
{
    if ( number <= 1 ) return false;

    for ( int i = 2; i * i <= number; i++ )
        if ( number % i == 0 ) return false;
    return true;
}

int solve(vector<char>& numList, string numberS)
{
    if ( numList.size() == 0 )
    {
        if ( numberS == "" ) return 0;

        int cnt = 0;
        sort(numberS.begin(), numberS.end());
        do
        {
            int number = stoi(numberS);
            if ( checked[number] ) continue;
            else checked[number] = true;

            if ( isPrime(number) ) cnt++;      
        }
        while ( next_permutation(numberS.begin(), numberS.end()) );

        return cnt;
    }

    char c = numList.back();
    numList.pop_back();
    int ret = solve(numList, numberS + c) + solve(numList, numberS);
    numList.push_back(c);
    return ret;
}

int solution(string numbers)
{
    vector<char> numList(numbers.begin(), numbers.end());

    int answer = solve(numList, "");
    return answer;
}