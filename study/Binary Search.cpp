#include <iostream>
#include <vector>
using namespace std;

// 반복문 불변식, 귀납법을 이용한 증명
int binsearch(const vector<int>& A, int x)
{
	int n = A.size();
	int lo = -1, hi = n;
	// 반복문 불변식 1 : lo < hi
	// 반복문 불변식 2 : A[lo] < x <= A[hi]
	while ( lo + 1 < hi ) // lo와 hi 차이가 2이상
	{
		int mid = (lo + hi) / 2;
		if ( A[mid] < x ) lo = mid;
		else hi = mid;
	}
	return hi;
}