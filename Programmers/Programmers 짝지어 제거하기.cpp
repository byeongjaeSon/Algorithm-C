#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;

    int answer = -1;

    int len = s.length();
    for ( int i = 0; i < len; i++ )
    {
        if ( st.empty() )
        {
            st.push(s[i]);
            continue;
        }

        if ( st.top() == s[i] )
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    if ( st.empty() ) answer = 1;
    else answer = 0;

    return answer;
}