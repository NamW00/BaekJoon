#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int test, days, maxVal;
    long long result;
    cin >> test;
    while (test--)
    {
        cin >> days;
        int stock[1000000] = {0,};
        for (int i = 0; i < days; i++)
        {
            cin >> stock[i];
        }

        result = 0;
        maxVal = stock[days - 1];

        for (int i = days - 2; i >= 0; i--)
        {
            maxVal = max(maxVal, stock[i]);
            result += maxVal - stock[i];
        }   
        cout << result << endl;
    }
    return 0;
}