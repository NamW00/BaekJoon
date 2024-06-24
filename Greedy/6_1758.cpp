#include <iostream>
#include <algorithm>

using namespace std;

int tip[100001];

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
        cin >> tip[i];
    }

    sort(tip, tip + n, compare);

    for (int i = 0; i < n; i++)
    {
        int result = tip[i] - i;
        if (result > 0)
        {
            sum += result;
        }
    }

    cout << sum;

    return 0;
}