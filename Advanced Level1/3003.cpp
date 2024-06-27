#include <iostream>
using namespace std;

int main()
{
    int a[6] = {1, 1, 2, 2, 2, 8};
    int b[6] = {0,};
    for (int i = 0; i < 6; i++)
    {
        cin >> b[i];
        a[i] -= b[i];
        cout << b[i] << " ";
    }

    return 0;
}