#include <iostream>
#include <algorithm>

using namespace std;

long long loss[100001];


int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> loss[i];
    }

    sort(loss, loss + n);

    long long m = 0;
    long long minloss = 0;

    if (n % 2 == 1)
    {
        minloss = loss[n - 1];
        n--;
    }
    for (int i = 0; i < n / 2; i++)
    {
        m = loss[i] + loss[n - 1 - i];
        minloss = max(minloss, m);
    }
    
    cout << minloss;

    return 0;
}