#include <iostream>

using namespace std;


int main()
{
    int n, x, y, count = 0;
    int area[100][100] = {0,};
    cin >> n;
    
    while (n--)
    {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                if (!area[i][j])
                {
                    count++;
                    area[i][j] = 1;
                }
            }        
        }
    }
    cout << count << endl;

    return 0;
}