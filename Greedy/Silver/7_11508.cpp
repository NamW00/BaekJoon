#include <iostream>
#include <algorithm>

using namespace std;
long long value[100001];
bool compare(long long i, long long j)
{
    return j < i;
}

int main()
{
    int n = 0;
    long long sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    sort(value, value + n, compare);
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0 || i % 3 == 1)
        {
            sum += value[i];
        }
    }
    cout << sum;

    return 0;
}