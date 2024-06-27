#include <iostream>
using namespace std;

int main()
{
    int array[10][10];
    int maxI, maxJ, maxA = -1;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> array[i][j];

            if (maxA < array[i][j])
            {
                maxA = array[i][j];
                maxI = i;
                maxJ = j;
            }
        }  
    }
    
    cout << maxA << endl;
    cout << maxI << ' ' << maxJ;

    return 0;
}