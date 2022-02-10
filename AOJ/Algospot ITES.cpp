#include <iostream>
#include <queue>
using namespace std;

struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next()
	{
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n)
{
	RNG rng; // ��ȣ���� �����ϴ� ���� ������
	queue<int> range; // ���� ������ ����ִ� ���ڵ��� �����ϴ� ť
	int ret = 0, rangeSum = 0;
	for ( int i = 0; i < n; i++ )
	{
		//������ ���ڸ� �߰��Ѵ�.
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		// ������ ���� k�� �ʰ��ϴ� ���� �������� ���ڸ� ����.
		while ( rangeSum > k )
		{
			rangeSum -= range.front();
			range.pop();
		}

		if ( rangeSum == k ) ret++;
	}
	return ret;
}


int main()
{
	int C, n, k;
	cin >> C;
	
	while ( C-- )
	{
		cin >> k >> n;
		cout << countRanges(k, n) << '\n';
	}

	return 0;
}