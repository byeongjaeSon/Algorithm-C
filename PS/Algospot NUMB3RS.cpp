#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int A[51][51];
int cntOfConnected[51];
double** initial_pos;
double** transition_matrix;
int N, D, P, T;

void init_function()
{
	memset(cntOfConnected, 0, sizeof(cntOfConnected));

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			cin >> A[i][j];
			if ( A[i][j] == 1 ) cntOfConnected[i]++;
		}
	}

	initial_pos = new double* [1];
	initial_pos[0] = new double[N] { 0 };
	initial_pos[0][P] = 1;

	transition_matrix = new double* [N];
	for ( int i = 0; i < N; ++i )
		transition_matrix[i] = new double[N] {0};

	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < N; j++ )
			if ( A[i][j] == 1 ) transition_matrix[i][j] = 1.0 / cntOfConnected[i];
}

void copyMatrix(double** m1, double** m2, int N)
{
	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < N; j++ )
			m1[i][j] = m2[i][j];
}

double** multiplyMatrix(double** m1, int row1, int col1, double** m2, int row2, int col2)
{
	if ( col1 != row2 )
		return nullptr;

	double** ret = new double* [row1];
	for ( int i = 0; i < row1; ++i )
	{
		ret[i] = new double[col2] {0};
	}

	int i, j, k;

	for ( i = 0; i < row1; i++ )
		for ( j = 0; j < col2; j++ )
			for ( k = 0; k < col1; k++ )
				ret[i][j] += m1[i][k] * m2[k][j];

	return ret;
}

int main()
{
	int C;
	cin >> C;
	while ( C-- )
	{
		cin >> N >> D >> P;
		init_function();
		double** ret = new double* [N];
		for ( int i = 0; i < N; ++i )
			ret[i] = new double[N] {0};
		
		copyMatrix(ret, transition_matrix, N);
		for ( int i = 0; i < D-1; i++ )
			copyMatrix(ret, multiplyMatrix(ret, N, N, transition_matrix, N, N), N);
			
		ret = multiplyMatrix(initial_pos, 1, N, ret, N, N);

		cin >> T;
		for ( int i = 0; i < T; i++ )
		{
			int town;
			cin >> town;
			cout << fixed << setprecision(8) << ret[0][town] << ' ';
		}
		cout << '\n';
	}
	return 0;
}