#include <iostream>
using namespace std;

int main()
{
    int n, line;
    cin >> n;
    line = 2 * n - 1;
    for (int i = 1; i <= line; i++)
    {
        if (i <= n)
        {
            for (int j = 1; j <= n - i; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for (int j = 1; j <= i - n; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= 2 * (line - i) + 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }     
    }
    return 0;
}