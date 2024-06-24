#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    long long time[100001];
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    sort(time, time + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += time[j];
        }
    }
    cout << sum;
    return 0;
}