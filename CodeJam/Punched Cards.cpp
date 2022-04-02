//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int t, r, c;
//    cin >> t;
//
//    for ( int testCase = 1; testCase <= t; testCase++ )
//    {
//        cout << "Case #" << testCase << ":\n";
//        cin >> r >> c;
//        for ( int row = 0; row < 2 * r + 1; row++ )
//        {
//            for ( int col = 0; col < 2 * c + 1; col++ )
//            {
//                if ( row + col <= 1 )
//                {
//                    cout << ".";
//                    continue;
//                }
//
//                if ( row % 2 == 0 && col % 2 == 0 ) cout << "+";
//                else if ( row % 2 == 0 && col % 2 == 1 ) cout << "-";
//                else if ( row % 2 == 1 && col % 2 == 0 ) cout << "|";
//                else if ( row % 2 == 1 && col % 2 == 1 ) cout << ".";
//            }
//            cout << '\n';
//        }
//    }
//    return 0;
//}