//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int AMOUNT = 1000000;
//
//int main()
//{
//    int t;
//    cin >> t;
//
//    for ( int testCase = 1; testCase <= t; testCase++ )
//    {
//        vector<vector<int>> printers;
//        for ( int i = 0; i < 3; i++ )
//        {
//            vector<int> inks(4);
//            for ( int j = 0; j < 4; j++ )
//                cin >> inks[j];
//
//            printers.push_back(inks);
//        }
//
//        cout << "Case #" << testCase << ": ";
//
//        int minC = min({ printers[0][0], printers[1][0], printers[2][0] });
//        int minM = min({ printers[0][1], printers[1][1], printers[2][1] });
//        int minY = min({ printers[0][2], printers[1][2], printers[2][2] });
//        int minK = min({ printers[0][3], printers[1][3], printers[2][3] });
//
//        vector<int> colors = { minC, minM, minY, minK };
//
//        if ( minC + minM + minY + minK < AMOUNT )
//        {
//            cout << "IMPOSSIBLE \n";
//            continue;
//        }
//
//        int target = AMOUNT;
//        for ( int i = 0; i < 4; i++ )
//        {
//            if ( target <= 0 ) cout << 0 << " ";
//            else
//            {
//                cout << min(AMOUNT, colors[i]) << " ";
//                target -= colors[i];
//            }
//        }
//        cout << '\n';
//    }
//
//    return 0;
//}