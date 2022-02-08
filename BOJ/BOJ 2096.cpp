#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987564321

int score[2][3];
int maxScore[2][3];
int minScore[2][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < 3; i++ )
		cin >> score[0][i];

	fill(&minScore[0][0], &minScore[1][3], INF);

	for ( int i = 0; i < 3; i++ )
		maxScore[0][i] = minScore[0][i] = score[0][i];


	int height = 1, prevH = 0;
	for ( int h = 1; h < n; h++ )
	{
		height = h % 2 == 1 ? 1 : 0;
		prevH = height == 1 ? 0 : 1;

		for ( int i = 0; i < 3; i++ )
			cin >> score[height][i];

		for ( int col = 0; col < 3; col++ )
		{
			if ( col - 1 < 0 )
			{
				maxScore[height][col] = score[height][col] + max(maxScore[prevH][col], maxScore[prevH][col + 1]);
				minScore[height][col] = score[height][col] + min(minScore[prevH][col], minScore[prevH][col + 1]);
			}
			else if ( col + 1 > 2 )
			{
				maxScore[height][col] = score[height][col] + max(maxScore[prevH][col - 1], maxScore[prevH][col]);
				minScore[height][col] = score[height][col] + min(minScore[prevH][col - 1], minScore[prevH][col]);
			}
			else
			{
				maxScore[height][col] = score[height][col] + max({ maxScore[prevH][col - 1], maxScore[prevH][col], maxScore[prevH][col + 1] });
				minScore[height][col] = score[height][col] + min({ minScore[prevH][col - 1], minScore[prevH][col], minScore[prevH][col + 1] });
			}

		}
	}

	if ( n == 1 ) height = 0; // 줄이 1개일 때 처리.

	cout << max({ maxScore[height][0], maxScore[height][1], maxScore[height][2] }) 
		<< " " << min({ minScore[height][0], minScore[height][1], minScore[height][2] });

	return 0;
}