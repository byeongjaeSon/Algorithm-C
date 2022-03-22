#include <iostream>
#include <vector>
using namespace std;

int sorted[500001];
long long ans = 0;

void merge(vector<int>& seq, int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;

	while ( i <= mid && j <= end )
	{
		if ( seq[i] <= seq[j] ) sorted[k++] = seq[i++];
		else
		{
			sorted[k++] = seq[j++];
			ans += mid - i + 1;
		}
	}

	if ( i > mid )
		for ( int t = j; t <= end; t++ ) sorted[k++] = seq[t];
	else
		for ( int t = i; t <= mid; t++ ) sorted[k++] = seq[t];

	for ( int t = start; t <= end; t++ ) seq[t] = sorted[t];
}

void merge_sort(vector<int>& seq, int start, int end)
{
	if ( start >= end ) return;

	int mid = (start + end) / 2;

	merge_sort(seq, start, mid);
	merge_sort(seq, mid + 1, end);

	merge(seq, start, mid, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> seq(n);
	for ( int i = 0; i < n; i++ )
		cin >> seq[i];

	merge_sort(seq, 0, n - 1);
	cout << ans << '\n';
	return 0;
}