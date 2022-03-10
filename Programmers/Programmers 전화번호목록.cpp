#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie
{
    bool isFinished;

    Trie* node[10];
    Trie()
    {
        for ( int i = 0; i < 10; i++ ) node[i] = NULL;
        isFinished = false;
    }

    bool insert(const char* str)
    {
        if ( str[0] != '\0' && isFinished ) return false;

        if ( str[0] == '\0' ) return isFinished = true;

        int curr = str[0] - '0';
        if ( node[curr] == NULL ) node[curr] = new Trie();
        return node[curr]->insert(str + 1);
    }
};

bool cmp(string& str1, string& str2)
{
    if ( str1.length() < str2.length() ) return true;
    else return false;
}

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end(), cmp);

    bool answer = true;

    Trie* root = new Trie();

    int len = phone_book.size();
    for ( int i = 0; i < len; i++ )
    {
        if ( !root->insert(phone_book[i].c_str()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}