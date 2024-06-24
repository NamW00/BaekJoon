#include <iostream>
#include <algorithm>

using namespace std;

bool compare(long long i, long long j)
{
    return i > j;
}

int drink[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> drink[i];
    }
    sort(drink, drink + n, compare);

    double sum = drink[0];

    for (int i = 1; i < n; i++)
    {
            sum += drink[i] / 2.;
    }
    
    cout << sum << endl;

    return 0;
}