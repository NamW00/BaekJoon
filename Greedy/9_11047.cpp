#include <iostream>
#include <algorithm>

using namespace std;

int coin[11];

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    
    int count = 0;

    for (int i = n-1; i >= 0; i--)
    {
        count += k / coin[i];
        k %= coin[i];
    }

    cout << count << endl;
    
    return 0;
}