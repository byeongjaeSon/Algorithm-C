#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{

    int lenOfordersOfskill = skill.length();
    vector<int> orders(26, -1);
    for ( int i = 0; i < skill.length(); i++ )
    {
        orders[skill[i] - 'A'] = i;
    }

    int answer = 0;
    int numOfskill_trees = skill_trees.size();
    for ( int i = 0; i < numOfskill_trees; i++ )
    {
        string skill_tree = skill_trees[i];
        int order = 0, j = 0;;
        int len = skill_tree.length();
        for ( j = 0; j < len; j++ )
        {

            if ( orders[skill_tree[j] - 'A'] == -1 ) continue;

            if ( orders[skill_tree[j] - 'A'] == order ) order++;
            else break;

            if ( order == lenOfordersOfskill )
            {
                answer++;
                break;
            }
        }
        if ( j == len ) answer++;
    }

    return answer;
}