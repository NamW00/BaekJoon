#include <iostream>
using namespace std;

int main()
{
    int n;
    string numList;
    
    cin >> n >> numList;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (numList[i] - 48);
    }
    cout << sum;
    return 0;
}