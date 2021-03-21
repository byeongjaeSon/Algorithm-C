#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 시간 복잡도 : N^2
void insertionSort(vector<int>& A)
{
	for ( int i = 0; i < A.size(); i++ )
	{
		int j = i;
		while ( j > 0 && A[j - 1] > A[j] )
		{
			swap(A[j - 1], A[j]);
			j--;
		}
	}
}